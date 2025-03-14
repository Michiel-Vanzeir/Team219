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
        "/milo/rldr2"};

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
        std::bind(&LdrGzSubscriber::send_ldr_readings, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "LDR Subscriber & server initialized.");
  }

private:
  std::vector<rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr> subscriptions_;
  rclcpp::Service<milo_communication::srv::LdrData>::SharedPtr service_;

  std::array<float, 4> forward_ldr_intensities_;
  std::array<float, 4> lateral_ldr_intensities_;

  void ldr_callback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    if (msg->data.empty())
    {
      RCLCPP_WARN(this->get_logger(), "Received an empty image!");
      return;
    }

    float total_intensity = 0.0;

    for (size_t i = 0; i < msg->data.size(); i += 3)
    {
      uint8_t r = msg->data[i];
      uint8_t g = msg->data[i + 1];
      uint8_t b = msg->data[i + 2];

      float light_intensity = 0.2989 * r + 0.5870 * g + 0.1140 * b;
      total_intensity += light_intensity;
    }

    float avg_intensity = total_intensity / (msg->height * msg->width);

    // Rescale avg_intensity (range 160 - 255) to range 1 - 3.3 to mimic LDR voltage readings
    avg_intensity = 1.2 + (avg_intensity/130)*2.1;
    
    std::string sensor_name = msg->header.frame_id;
    char position = sensor_name[sensor_name.length() - 2];
    std::string index_str = sensor_name.substr(sensor_name.length() - 1);
    int index = std::stoi(index_str);  

    // Check if the sensor input is valid
    if (avg_intensity >= 1.0 && avg_intensity <= 3.5) {
      // Store the intensity in the corresponding array (f = forward, l = lateral)
      if (position == 'f')
      {
        forward_ldr_intensities_[index] = avg_intensity;
      }
      else if (position == 'l')
      {
        lateral_ldr_intensities_[index] = avg_intensity;
      }
      else
      {
        RCLCPP_WARN(this->get_logger(), "Received data from an invalid LDR: %s", sensor_name.c_str());
      }
    } 
  }

  void send_ldr_readings(
      const std::shared_ptr<milo_communication::srv::LdrData::Request> request,
      std::shared_ptr<milo_communication::srv::LdrData::Response> response)
  {
    (void)request;

    // Now the types match perfectly
    response->forward_ldr_intensities = forward_ldr_intensities_;
    response->lateral_ldr_intensities = lateral_ldr_intensities_;
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
