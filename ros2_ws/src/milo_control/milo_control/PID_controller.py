from std_msgs.msg import Float32
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
            Float32, '/PID_input', self.input_callback, 2)
        self.publisher = self.create_publisher(Float32, '/PID_output', 2)

        # PID Controller
        self.pid_controller = PIDController(Kp=0.0025, Kd=0.0007, Ki=0)

    def input_callback(self, msg):
        position_error = msg.data

        # Calculate PID output
        pid_output = self.pid_controller.calculate(position_error)

        # Publish PID output
        output_msg = Float32()
        output_msg.data = pid_output
        self.publisher.publish(output_msg)

def main():
    rclpy.init()
    pid_node = PIDNode()
    rclpy.spin(pid_node)
    pid_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()