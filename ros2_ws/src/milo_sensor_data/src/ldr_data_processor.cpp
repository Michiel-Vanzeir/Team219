#include "rclcpp/rclcpp.hpp"
#include "milo_communication/srv/ldr_data.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <memory>
#include <vector>

class LdrGzSubscriber : public rclcpp::Node
{
public:
  LdrGzSubscriber()
  : Node("ldr_gz_subscriber")
  {
    // All Gazebo LDR topics
    std::vector<std::string> ldr_topics = {
      "/milo/fldr1",
      "/milo/fldr2",
      "/milo/bldr1",
      "/milo/bldr2",
      "/milo/lldr1",
      "/milo/lldr2",
      "/milo/rldr1",
      "/milo/rldr2"
    };
    
    // Initialize the ldr subscribers
    for (const auto &topic : ldr_topics) 
    {
      auto sub = create_subscription<sensor_msgs::msg::Image>(
        topic, 2, // Max queue size of 2
        std::bind(&LdrGzSubscriber::ldr_callback, this, std::placeholders::_1));
      
      subscriptions_.push_back(sub);
    }

    // Initialize the service server
    service_ = this->create_service<milo_communication::srv::LdrData>(
      "/get_ldr_readings", 
      std::bind(&LdrGzSubscriber::send_ldr_readings, this, std::placeholders::_1, std::placeholders::_2)
    );

    RCLCPP_INFO(this->get_logger(), "LDR Subscriber & server initialized.");
  }

private:
  std::vector<rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr> subscriptions_;
  rclcpp::Service<milo_communication::srv::LdrData>::SharedPtr service_;

  void ldr_callback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    // Identify the LDR sensor via frame_id
    std::string sensor_name = msg->header.frame_id;

    RCLCPP_INFO(this->get_logger(), "Received data from LDR: %s", sensor_name.c_str());

  }

  void send_ldr_readings(
    const std::shared_ptr<milo_communication::srv::LdrData::Request> request,
    std::shared_ptr<milo_communication::srv::LdrData::Response> response)
  {
    // Suppress the unused parameter warnings
    (void)request;
    (void)response;
  
    RCLCPP_INFO(this->get_logger(), "Do nothing");
  }
  
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<LdrGzSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
