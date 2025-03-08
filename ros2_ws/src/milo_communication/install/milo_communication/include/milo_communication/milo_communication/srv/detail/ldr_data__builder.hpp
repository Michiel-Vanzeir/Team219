// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "milo_communication/srv/ldr_data.hpp"


#ifndef MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__BUILDER_HPP_
#define MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "milo_communication/srv/detail/ldr_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace milo_communication
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::milo_communication::srv::LdrData_Request>()
{
  return ::milo_communication::srv::LdrData_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace milo_communication


namespace milo_communication
{

namespace srv
{

namespace builder
{

class Init_LdrData_Response_forward_ldr_intensities
{
public:
  explicit Init_LdrData_Response_forward_ldr_intensities(::milo_communication::srv::LdrData_Response & msg)
  : msg_(msg)
  {}
  ::milo_communication::srv::LdrData_Response forward_ldr_intensities(::milo_communication::srv::LdrData_Response::_forward_ldr_intensities_type arg)
  {
    msg_.forward_ldr_intensities = std::move(arg);
    return std::move(msg_);
  }

private:
  ::milo_communication::srv::LdrData_Response msg_;
};

class Init_LdrData_Response_lateral_ldr_intensities
{
public:
  Init_LdrData_Response_lateral_ldr_intensities()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LdrData_Response_forward_ldr_intensities lateral_ldr_intensities(::milo_communication::srv::LdrData_Response::_lateral_ldr_intensities_type arg)
  {
    msg_.lateral_ldr_intensities = std::move(arg);
    return Init_LdrData_Response_forward_ldr_intensities(msg_);
  }

private:
  ::milo_communication::srv::LdrData_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::milo_communication::srv::LdrData_Response>()
{
  return milo_communication::srv::builder::Init_LdrData_Response_lateral_ldr_intensities();
}

}  // namespace milo_communication


namespace milo_communication
{

namespace srv
{

namespace builder
{

class Init_LdrData_Event_response
{
public:
  explicit Init_LdrData_Event_response(::milo_communication::srv::LdrData_Event & msg)
  : msg_(msg)
  {}
  ::milo_communication::srv::LdrData_Event response(::milo_communication::srv::LdrData_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::milo_communication::srv::LdrData_Event msg_;
};

class Init_LdrData_Event_request
{
public:
  explicit Init_LdrData_Event_request(::milo_communication::srv::LdrData_Event & msg)
  : msg_(msg)
  {}
  Init_LdrData_Event_response request(::milo_communication::srv::LdrData_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_LdrData_Event_response(msg_);
  }

private:
  ::milo_communication::srv::LdrData_Event msg_;
};

class Init_LdrData_Event_info
{
public:
  Init_LdrData_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LdrData_Event_request info(::milo_communication::srv::LdrData_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_LdrData_Event_request(msg_);
  }

private:
  ::milo_communication::srv::LdrData_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::milo_communication::srv::LdrData_Event>()
{
  return milo_communication::srv::builder::Init_LdrData_Event_info();
}

}  // namespace milo_communication

#endif  // MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__BUILDER_HPP_
