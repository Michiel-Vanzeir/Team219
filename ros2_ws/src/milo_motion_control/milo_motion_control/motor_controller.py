import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32
from geometry_msgs.msg import Twist


class MotorController(Node):

    def __init__(self):
        super().__init__('motor_controller')
        self.subscription = self.create_subscription(Float32, '/PID_output', self.pid_callback, 2)
        self.subscription  # prevent unused variable warning

        self.gzmotorpub = self.create_publisher(Twist, '/model/milo/cmd_vel', 2)

    def pid_callback(self, msg):
        motoroutput = Twist()
        motoroutput.linear.x = 0.05
        motoroutput.linear.y = msg.data
        self.gzmotorpub.publish(motoroutput)

def main(args=None):
    rclpy.init(args=args)

    motor_controller = MotorController()

    rclpy.spin(motor_controller)
    motor_controller.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()