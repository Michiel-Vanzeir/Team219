import threading
import time
import math
import numpy as np
import rclpy
from rclpy.node import Node
from milo_communication.srv import LdrData
from milo_communication.msg import PIDInput
from geometry_msgs.msg import Twist

class MainController(Node):
    def __init__(self):
        super().__init__('main_controller') # Node name
        self.client = self.create_client(LdrData, '/get_ldr_readings')
        self.pidpub = self.create_publisher(PIDInput, '/PID_input', 2)
        self.motorpub = self.create_publisher(Twist, '/model/milo/cmd_vel', 2)
        
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('LDR readings service not available, waiting...')

        self.request = LdrData.Request()

        # Set driving mode (FORWARD, LATERAL, TURNING)
        self.MODE = "FORWARD"
        self.near_intersection = False

        # Necessary LDR parameters
        self.max_ldr_reading = 3.3
        self.min_ldr_reading = 1.95
        self.threshold = (self.max_ldr_reading + self.min_ldr_reading) / 2
        self.ldr_distances_x = [0.0, 2.47, 3.5, 2.47, 0.0, -2.47, -3.5, -2.47]
        self.ldr_distances_y = [3.5, 2.47, 0.0, -2.47, -3.5, -2.47, 0, 2.47]
        self.sensor_angles = [i * (math.pi/4) for i in range(8)]
        self.ldr_circle_radius = 3.5
        self.ldr_turning_indices = [0, 2, 4, 6] # LDRs that need to be black to have turned 90 degrees

        # Wait for ROS to initialize
        time.sleep(10)

    def send_request(self):
        return self.client.call(self.request)

    # Detects whether the robot is on a grid intersection based on the amount of LDRs over a black line
    def onIntersection(self, ldr_readings):
        return sum(ldr_readings[index] < self.threshold for index in self.ldr_turning_indices) == 4

    def nearIntersection(self, ldr_readings):
        return sum(ldr_readings[index] < self.threshold for index in [3, 5])

    def turnRight(self):
        motor_cmd = Twist()
        motor_cmd.angular.z = -0.8
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
    def calculateLineDeviation(self, ldr_readings):
        line_deviation = 0.0
        total_activation = 0.0
        activation_range = self.max_ldr_reading - self.min_ldr_reading

        # Calculate the activations and weighted sum
        for reading, distance in zip(ldr_readings, self.ldr_distances_x):
            activation = 1 - (reading - self.min_ldr_reading) / activation_range
            line_deviation += activation * distance
            total_activation += activation

        if total_activation != 0:
            line_deviation /= total_activation

            return line_deviation
        else:
            return 0.0

    def compute_weighted_position(self, activations, neighboring_indices):
            weighted_x = 0.0
            weighted_y = 0.0
            total_activation = 0.0

            for index in neighboring_indices:
                weighted_x += activations[index] * self.ldr_distances_x[index]
                weighted_y += activations[index] * self.ldr_distances_y[index]
                total_activation += activations[index]

            if total_activation != 0:
                weighted_x /= total_activation
                weighted_y /= total_activation

            return weighted_x, weighted_y

    def calculateLineAngle(self, ldr_readings):
        activations = []
        activation_range = self.max_ldr_reading - self.min_ldr_reading

        # Variables to track the indices of the two highest activations
        highest_activation_idx = -1
        second_highest_activation_idx = -1
        highest_activation = 0.0
        second_highest_activation = 0.0

        # Calculate activations for each LDR
        for index, reading in enumerate(ldr_readings):
            activation = 1 - (reading - self.min_ldr_reading) / activation_range
            activations.append(activation)

            # Update highest and second highest activations
            if activation > highest_activation:
                second_highest_activation = highest_activation
                second_highest_activation_idx = highest_activation_idx
                highest_activation = activation
                highest_activation_idx = index
            elif activation > second_highest_activation:
                second_highest_activation = activation
                second_highest_activation_idx = index

        # Make sure the highest index is in the front of the robot
        if highest_activation_idx not in {7, 0, 1}:
            temp_idx = highest_activation_idx
            highest_activation_idx = second_highest_activation_idx
            second_highest_activation_idx = temp_idx

        # Select neighboring LDRs of the two most activated ones
        highest_neighbors = [(highest_activation_idx - 1) % 8, highest_activation_idx, (highest_activation_idx + 1) % 8]
        second_highest_neighbors = [(second_highest_activation_idx - 1) % 8, second_highest_activation_idx, (second_highest_activation_idx + 1) % 8]

        # Calculate the weighted line intersects
        weighted_x1, weighted_y1 = self.compute_weighted_position(activations, highest_neighbors)
        weighted_x2, weighted_y2 = self.compute_weighted_position(activations, second_highest_neighbors)

        # Calculate the line angle
        delta_x = weighted_x2 - weighted_x1
        delta_y = abs(weighted_y2 - weighted_y1)
        angle = math.degrees(math.atan2(delta_y, delta_x)) - 90


        self.get_logger().debug(f"Angle: {angle}")
        self.get_logger().debug(f"      {activations[0]}      ")
        self.get_logger().debug(f"   {activations[7]}     {activations[1]}   ")
        self.get_logger().debug(f" {activations[6]}         {activations[2]} ")
        self.get_logger().debug(f"   {activations[5]}     {activations[3]}   ")
        self.get_logger().debug(f"      {activations[4]}      ")
        return angle

    def sendPIDInput(self, line_deviation, line_angle):
        pid_input = PIDInput()
        pid_input.position_error = line_deviation
        pid_input.angle_error = line_angle
        self.pidpub.publish(pid_input)

    def main_control_loop(self, ldr_data):
        readings = ldr_data.ldr_readings

        if self.MODE == "TURNING":
            if self.onIntersection(readings):
                self.stop()
                self.driveForwards(velocity=0.1, duration=1)
                self.MODE = "FORWARD"
                self.near_intersection = False
                self.get_logger().info("AWAY FROM INTERSECTION")
        elif self.onIntersection(readings):
            self.turnRight()
            self.MODE = "TURNING"
            self.get_logger().info("TURNING")
        elif self.near_intersection:
            line_deviation = self.calculateLineDeviation(readings)
            self.sendPIDInput(line_deviation, 0.0)
        else:
            line_deviation = self.calculateLineDeviation(readings)
            line_angle = self.calculateLineAngle(readings)
            self.sendPIDInput(line_deviation, line_angle)

            self.near_intersection = self.nearIntersection(readings)
            if self.near_intersection:
                self.get_logger().info("NEAR INTERSECTION")



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
            time.sleep(0.25)  # Client request Hz 
    except KeyboardInterrupt:
        main_controller.get_logger().info("KeyboardInterrupt, shutting down.")
    finally:
        main_controller.destroy_node()
        rclpy.shutdown()
        spin_thread.join()

if __name__ == '__main__':
    main()
