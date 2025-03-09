import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32
from geometry_msgs.msg import Twist


class MotorController(Node):

    def __init__(self):
        super().__init__('motor_controller')
        self.subscription = self.create_subscription(Float32, '/PID_output', self.pid_callback, 2)
        self.subscription  # prevent unused variable warning

        self.publisher = self.create_publisher(Twist, '/model/milo/cmd_vel', 2)

    def pid_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)

        msg = Twist()
        msg.linear.x = 0.5
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    motor_controller = MotorController()

    rclpy.spin(motor_controller)
    motor_controller.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()