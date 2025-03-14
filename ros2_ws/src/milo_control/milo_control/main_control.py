import threading
import time
import rclpy
from rclpy.node import Node
from milo_communication.srv import LdrData
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist

class MainController(Node):
    def __init__(self):
        super().__init__('main_controller') # Node name
        self.client = self.create_client(LdrData, '/get_ldr_readings')
        self.pidpub = self.create_publisher(Float32, '/PID_input', 2)
        self.motorpub = self.create_publisher(Twist, '/model/milo/cmd_vel', 2)
        
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('LDR readings service not available, waiting...')

        self.request = LdrData.Request()

        # Set driving mode (FORWARD, LATERAL, TURNING)
        self.MODE = "FORWARD"

        # Necessary LDR parameters
        self.max_ldr_reading = 3.3
        self.min_ldr_reading = 1.95
        self.threshold = (self.max_ldr_reading + self.min_ldr_reading) / 2 
        self.ldr_distances = [-5.0, -2.5, 2.5, 5.0]

        # Wait for ROS to initialize
        time.sleep(10)

    def send_request(self):
        return self.client.call(self.request)

    # Detects whether the robot is on a grid intersection based on the amount of LDRs over a black line
    def onIntersection(self, ldr_readings, min_triggered_ldrs):
        return sum(reading < self.threshold for reading in ldr_readings) >= min_triggered_ldrs

    def turnRight(self):
        motor_cmd = Twist()
        motor_cmd.angular.z = -0.5
        self.motorpub.publish(motor_cmd)
        time.sleep(2)

    def stop(self):
        self.motorpub.publish(Twist()) # All velocities are zero by default

    def driveForwards(self, duration, velocity: float):
        motor_cmd = Twist()
        motor_cmd.linear.x = velocity
        self.motorpub.publish(motor_cmd)

        time.sleep(duration)

        motor_cmd.linear.x = 0.0
        self.motorpub.publish(motor_cmd)

    # Calculates the deviation from the line using a weighted average
    def sendPIDInput(self, ldr_readings):
        line_deviation = 0.0
        total_activation = 0.0
        activation_range = self.max_ldr_reading - self.min_ldr_reading

        # Calculate the activations and weighted sum
        for reading, distance in zip(ldr_readings, self.ldr_distances):
            activation = 1 - (reading - self.min_ldr_reading) / activation_range
            line_deviation += activation * distance
            total_activation += activation

        if total_activation != 0:
            line_deviation /= total_activation

            pid_input = Float32()
            pid_input.data = line_deviation
            self.pidpub.publish(pid_input)
        else:
            self.get_logger().warn("Total activation is zero, skipping LDR readings.")

    def main_control_loop(self, ldr_data):

        if self.MODE == "TURNING":
            readings = list(ldr_data.lateral_ldr_intensities) + list(ldr_data.forward_ldr_intensities)
            if self.onIntersection(readings, min_triggered_ldrs=8):
                self.stop()
                self.driveForwards(velocity=0.1, duration=2)
                self.MODE = "FORWARD"
            return

        # Select readings based on the current mode
        readings = (
            ldr_data.lateral_ldr_intensities
            if self.MODE == "FORWARD"
            else ldr_data.forward_ldr_intensities
        )

        # Check for a grid intersection
        if self.onIntersection(readings, min_triggered_ldrs=3):
            self.turnRight()
            self.MODE = "TURNING"
        else:
            self.sendPIDInput(readings)


def main():
    rclpy.init()
    main_controller = MainController()

    # Spin the node in a separate thread to process service responses.
    spin_thread = threading.Thread(target=rclpy.spin, args=(main_controller,), daemon=True)
    spin_thread.start()

    try:
        while rclpy.ok():
            response = main_controller.send_request()
            if response is not None:
                main_controller.main_control_loop(response)
            else:
                main_controller.get_logger().warn("Received empty sensor data")
            time.sleep(0.05)  # Client request Hz 
    except KeyboardInterrupt:
        main_controller.get_logger().info("KeyboardInterrupt, shutting down.")
    finally:
        main_controller.destroy_node()
        rclpy.shutdown()
        spin_thread.join()

if __name__ == '__main__':
    main()
