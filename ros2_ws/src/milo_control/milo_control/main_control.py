import threading
import time
import rclpy
from rclpy.node import Node
from milo_communication.srv import LdrData
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist

class MainController(Node):

    def __init__(self):
        super().__init__('main_controller')  # Node name
        self.cli = self.create_client(LdrData, '/get_ldr_readings')
        self.pidpub = self.create_publisher(Float32, '/PID_input', 2)
        self.motorpub = self.create_publisher(Twist, '/model/milo/cmd_vel', 2)
        
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

        self.req = LdrData.Request()

        # Set driving mode (forward or sideways)
        self.MODE = "FORWARD"

        # These will change during the calibration phase (To do)
        self.max_ldr_reading = 3.27
        self.min_ldr_reading = 1.95

        self.ldr_distances = [-5.0, -2.5, 2.5, 5.0]

        # For grid intersection detection
        self.threshold = (self.max_ldr_reading + self.min_ldr_reading) / 2 

        # Wait for ROS to initialize
        time.sleep(5)

    def detect_grid_intersection(self, ldr_readings):
        thresholded_ldr_readings = []
        for reading in ldr_readings:
            if reading > self.threshold:
                thresholded_ldr_readings.append(0)
            else:
                thresholded_ldr_readings.append(1)

        # Check if at least 3 out of 4 LDRs detect an intersection
        return sum(thresholded_ldr_readings) >= 3

    def turn_right(self):
        motor_cmd = Twist()
        # Set the angular velocity to rotate 90 degrees to the right (clockwise)
        motor_cmd.angular.z = -0.8
        self.motorpub.publish(motor_cmd)
        time.sleep(1.825)
        # Stop the robot after turning
        motor_cmd.angular.z = 0.0
        self.motorpub.publish(motor_cmd)
        self.get_logger().info("STOPPED TURNING")

    def move_forward(self):
        motor_cmd = Twist()
        # Set the angular velocity to rotate 90 degrees to the right (clockwise)
        motor_cmd.linear.x = -0.05
        self.motorpub.publish(motor_cmd)
        time.sleep(0.5)
        # Stop the robot after turning
        motor_cmd.linear.x = 0.0
        self.motorpub.publish(motor_cmd)
        self.get_logger().info("STOPPED MOVING FORWARD")

    def main_control_loop(self, sensor_input):
        # Check which LDR readings to use
        if self.MODE == "FORWARD":
            sensor_input = sensor_input.lateral_ldr_intensities
            self.get_logger().info(f"Readings: {sensor_input[0]}, {sensor_input[1]}, {sensor_input[2]}, {sensor_input[3]}")
        else:
            sensor_input = sensor_input.forward_ldr_intensities

        # Check if the robot is on a grid intersection
        on_intersection = self.detect_grid_intersection(sensor_input)

        # Turn right for now (navigation will be added later)
        if on_intersection:
            self.get_logger().info("TURNING")
            self.turn_right()
            self.move_forward() # Make sure it's no longer on an intersection

        # Use the PID-controller to follow the line
        self.send_PID_input(sensor_input)

    def send_PID_input(self, sensor_input):
        # Give each LDR an activation value and calculate the weighted average
        line_deviation = 0.0
        total_activation = 0.0
        for reading, distance in zip(sensor_input, self.ldr_distances):
            activation = 1 - (reading - self.min_ldr_reading) / (self.max_ldr_reading - self.min_ldr_reading)
            line_deviation += activation * distance
            total_activation += activation

        if total_activation != 0:
            line_deviation /= total_activation
            pid_input = Float32()
            pid_input.data = line_deviation
            self.pidpub.publish(pid_input)
        else:
            self.get_logger().warn("Tried dividing weighted average by 0...")

    def send_request(self):
        return self.cli.call(self.req)

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
            time.sleep(0.1)  # Adjust the sleep duration as needed
    except KeyboardInterrupt:
        main_controller.get_logger().info("KeyboardInterrupt, shutting down.")
    finally:
        main_controller.destroy_node()
        rclpy.shutdown()
        spin_thread.join()

if __name__ == '__main__':
    main()
