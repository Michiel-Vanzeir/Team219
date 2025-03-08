// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "milo_communication/srv/ldr_data.hpp"


#ifndef MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__TRAITS_HPP_
#define MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "milo_communication/srv/detail/ldr_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace milo_communication
{

namespace srv
{

inline void to_flow_style_yaml(
  const LdrData_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LdrData_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LdrData_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace milo_communication

namespace rosidl_generator_traits
{

[[deprecated("use milo_communication::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const milo_communication::srv::LdrData_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  milo_communication::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use milo_communication::srv::to_yaml() instead")]]
inline std::string to_yaml(const milo_communication::srv::LdrData_Request & msg)
{
  return milo_communication::srv::to_yaml(msg);
}

template<>
inline const char * data_type<milo_communication::srv::LdrData_Request>()
{
  return "milo_communication::srv::LdrData_Request";
}

template<>
inline const char * name<milo_communication::srv::LdrData_Request>()
{
  return "milo_communication/srv/LdrData_Request";
}

template<>
struct has_fixed_size<milo_communication::srv::LdrData_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<milo_communication::srv::LdrData_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<milo_communication::srv::LdrData_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace milo_communication
{

namespace srv
{

inline void to_flow_style_yaml(
  const LdrData_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: lateral_ldr_intensities
  {
    if (msg.lateral_ldr_intensities.size() == 0) {
      out << "lateral_ldr_intensities: []";
    } else {
      out << "lateral_ldr_intensities: [";
      size_t pending_items = msg.lateral_ldr_intensities.size();
      for (auto item : msg.lateral_ldr_intensities) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: forward_ldr_intensities
  {
    if (msg.forward_ldr_intensities.size() == 0) {
      out << "forward_ldr_intensities: []";
    } else {
      out << "forward_ldr_intensities: [";
      size_t pending_items = msg.forward_ldr_intensities.size();
      for (auto item : msg.forward_ldr_intensities) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LdrData_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lateral_ldr_intensities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lateral_ldr_intensities.size() == 0) {
      out << "lateral_ldr_intensities: []\n";
    } else {
      out << "lateral_ldr_intensities:\n";
      for (auto item : msg.lateral_ldr_intensities) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: forward_ldr_intensities
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.forward_ldr_intensities.size() == 0) {
      out << "forward_ldr_intensities: []\n";
    } else {
      out << "forward_ldr_intensities:\n";
      for (auto item : msg.forward_ldr_intensities) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LdrData_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace milo_communication

namespace rosidl_generator_traits
{

[[deprecated("use milo_communication::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const milo_communication::srv::LdrData_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  milo_communication::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use milo_communication::srv::to_yaml() instead")]]
inline std::string to_yaml(const milo_communication::srv::LdrData_Response & msg)
{
  return milo_communication::srv::to_yaml(msg);
}

template<>
inline const char * data_type<milo_communication::srv::LdrData_Response>()
{
  return "milo_communication::srv::LdrData_Response";
}

template<>
inline const char * name<milo_communication::srv::LdrData_Response>()
{
  return "milo_communication/srv/LdrData_Response";
}

template<>
struct has_fixed_size<milo_communication::srv::LdrData_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<milo_communication::srv::LdrData_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<milo_communication::srv::LdrData_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace milo_communication
{

namespace srv
{

inline void to_flow_style_yaml(
  const LdrData_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LdrData_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LdrData_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace milo_communication

namespace rosidl_generator_traits
{

[[deprecated("use milo_communication::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const milo_communication::srv::LdrData_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  milo_communication::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use milo_communication::srv::to_yaml() instead")]]
inline std::string to_yaml(const milo_communication::srv::LdrData_Event & msg)
{
  return milo_communication::srv::to_yaml(msg);
}

template<>
inline const char * data_type<milo_communication::srv::LdrData_Event>()
{
  return "milo_communication::srv::LdrData_Event";
}

template<>
inline const char * name<milo_communication::srv::LdrData_Event>()
{
  return "milo_communication/srv/LdrData_Event";
}

template<>
struct has_fixed_size<milo_communication::srv::LdrData_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<milo_communication::srv::LdrData_Event>
  : std::integral_constant<bool, has_bounded_size<milo_communication::srv::LdrData_Request>::value && has_bounded_size<milo_communication::srv::LdrData_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<milo_communication::srv::LdrData_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<milo_communication::srv::LdrData>()
{
  return "milo_communication::srv::LdrData";
}

template<>
inline const char * name<milo_communication::srv::LdrData>()
{
  return "milo_communication/srv/LdrData";
}

template<>
struct has_fixed_size<milo_communication::srv::LdrData>
  : std::integral_constant<
    bool,
    has_fixed_size<milo_communication::srv::LdrData_Request>::value &&
    has_fixed_size<milo_communication::srv::LdrData_Response>::value
  >
{
};

template<>
struct has_bounded_size<milo_communication::srv::LdrData>
  : std::integral_constant<
    bool,
    has_bounded_size<milo_communication::srv::LdrData_Request>::value &&
    has_bounded_size<milo_communication::srv::LdrData_Response>::value
  >
{
};

template<>
struct is_service<milo_communication::srv::LdrData>
  : std::true_type
{
};

template<>
struct is_service_request<milo_communication::srv::LdrData_Request>
  : std::true_type
{
};

template<>
struct is_service_response<milo_communication::srv::LdrData_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__TRAITS_HPP_
