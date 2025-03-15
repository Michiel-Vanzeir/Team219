from milo_communication.msg import PIDInput, PIDOutput
import rclpy
from rclpy.node import Node

class PIDController:
    def __init__(self, Kp=0, Kd=0, Ki=0):
        self.Kp = Kp
        self.Kd = Kd
        self.Ki = Ki

        # For derivative gain
        self.previous_error = 0

        # For integral gain
        self.cumulative_error = 0

    def calculate(self, error):
        derivative_gain = error - self.previous_error

        # Update controller state
        self.previous_error = error
        self.cumulative_error += error

        return self.Kp * error + self.Kd * derivative_gain + self.Ki * self.cumulative_error

class PIDNode(Node):

    def __init__(self):
        super().__init__('pid_node')  # Node name
        self.subscription = self.create_subscription(
            PIDInput, '/PID_input', self.input_callback, 2)
        self.outputpub = self.create_publisher(PIDOutput, '/PID_output', 2)

        # PID Controller
        self.position_pid_controller = PIDController(Kp=0.0025, Kd=0.0007, Ki=0)
        self.angle_pid_controller = PIDController(Kp=0.025, Kd=0.0, Ki=0.0)

    def input_callback(self, msg):
        # Publish PID output
        output_msg = PIDOutput()
        output_msg.position_correction = self.position_pid_controller.calculate(msg.position_error)
        output_msg.orientation_correction = self.angle_pid_controller.calculate(msg.angle_error)
        self.outputpub.publish(output_msg)

def main():
    rclpy.init()
    pid_node = PIDNode()
    rclpy.spin(pid_node)
    pid_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()