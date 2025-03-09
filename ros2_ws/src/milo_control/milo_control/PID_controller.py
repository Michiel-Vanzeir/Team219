from milo_communication.srv import LdrData
from std_msgs.msg import Float32
import time
import rclpy
from rclpy.node import Node

class PIDClientAsync(Node):

    def __init__(self):
        super().__init__('pid_client')  # Node name
        self.cli = self.create_client(LdrData, '/get_ldr_readings')
        self.publisher = self.create_publisher(Float32, '/PID_output', 2)
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        

        self.req = LdrData.Request()

        # Wait five seconds for ROS to initialize everything (prevents 0.0 readings from service)
        time.sleep(5)

        # Timer to send request every 200ms
        self.timer = self.create_timer(1, self.send_request)

    # Make a service request (asynchronously)
    def send_request(self):
        future = self.cli.call_async(self.req)
        future.add_done_callback(self.handle_response)

    def handle_response(self, future):
        try:
            response = future.result()

            # Log the LDR intensities
            self.get_logger().info(
                f"Lateral LDR intensities: {response.lateral_ldr_intensities[0]:.2f}, "
                f"{response.lateral_ldr_intensities[1]:.2f}, "
                f"{response.lateral_ldr_intensities[2]:.2f}, "
                f"{response.lateral_ldr_intensities[3]:.2f}")
            
            msg = Float32()
            msg.data = 3.14 # Temporary test value
            self.publisher.publish(msg)

        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")

def main():
    rclpy.init()
    pid_client = PIDClientAsync()
    rclpy.spin(pid_client)
    pid_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
