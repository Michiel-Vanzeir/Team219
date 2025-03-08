// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "milo_communication/srv/ldr_data.hpp"


#ifndef MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_HPP_
#define MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__milo_communication__srv__LdrData_Request __attribute__((deprecated))
#else
# define DEPRECATED__milo_communication__srv__LdrData_Request __declspec(deprecated)
#endif

namespace milo_communication
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LdrData_Request_
{
  using Type = LdrData_Request_<ContainerAllocator>;

  explicit LdrData_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit LdrData_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    milo_communication::srv::LdrData_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const milo_communication::srv::LdrData_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__milo_communication__srv__LdrData_Request
    std::shared_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__milo_communication__srv__LdrData_Request
    std::shared_ptr<milo_communication::srv::LdrData_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LdrData_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const LdrData_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LdrData_Request_

// alias to use template instance with default allocator
using LdrData_Request =
  milo_communication::srv::LdrData_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace milo_communication


#ifndef _WIN32
# define DEPRECATED__milo_communication__srv__LdrData_Response __attribute__((deprecated))
#else
# define DEPRECATED__milo_communication__srv__LdrData_Response __declspec(deprecated)
#endif

namespace milo_communication
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LdrData_Response_
{
  using Type = LdrData_Response_<ContainerAllocator>;

  explicit LdrData_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->lateral_ldr_intensities.begin(), this->lateral_ldr_intensities.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->forward_ldr_intensities.begin(), this->forward_ldr_intensities.end(), 0.0f);
    }
  }

  explicit LdrData_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : lateral_ldr_intensities(_alloc),
    forward_ldr_intensities(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->lateral_ldr_intensities.begin(), this->lateral_ldr_intensities.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->forward_ldr_intensities.begin(), this->forward_ldr_intensities.end(), 0.0f);
    }
  }

  // field types and members
  using _lateral_ldr_intensities_type =
    std::array<float, 4>;
  _lateral_ldr_intensities_type lateral_ldr_intensities;
  using _forward_ldr_intensities_type =
    std::array<float, 4>;
  _forward_ldr_intensities_type forward_ldr_intensities;

  // setters for named parameter idiom
  Type & set__lateral_ldr_intensities(
    const std::array<float, 4> & _arg)
  {
    this->lateral_ldr_intensities = _arg;
    return *this;
  }
  Type & set__forward_ldr_intensities(
    const std::array<float, 4> & _arg)
  {
    this->forward_ldr_intensities = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    milo_communication::srv::LdrData_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const milo_communication::srv::LdrData_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__milo_communication__srv__LdrData_Response
    std::shared_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__milo_communication__srv__LdrData_Response
    std::shared_ptr<milo_communication::srv::LdrData_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LdrData_Response_ & other) const
  {
    if (this->lateral_ldr_intensities != other.lateral_ldr_intensities) {
      return false;
    }
    if (this->forward_ldr_intensities != other.forward_ldr_intensities) {
      return false;
    }
    return true;
  }
  bool operator!=(const LdrData_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LdrData_Response_

// alias to use template instance with default allocator
using LdrData_Response =
  milo_communication::srv::LdrData_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace milo_communication


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__milo_communication__srv__LdrData_Event __attribute__((deprecated))
#else
# define DEPRECATED__milo_communication__srv__LdrData_Event __declspec(deprecated)
#endif

namespace milo_communication
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LdrData_Event_
{
  using Type = LdrData_Event_<ContainerAllocator>;

  explicit LdrData_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit LdrData_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<milo_communication::srv::LdrData_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<milo_communication::srv::LdrData_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<milo_communication::srv::LdrData_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<milo_communication::srv::LdrData_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<milo_communication::srv::LdrData_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<milo_communication::srv::LdrData_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<milo_communication::srv::LdrData_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<milo_communication::srv::LdrData_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    milo_communication::srv::LdrData_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const milo_communication::srv::LdrData_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      milo_communication::srv::LdrData_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__milo_communication__srv__LdrData_Event
    std::shared_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__milo_communication__srv__LdrData_Event
    std::shared_ptr<milo_communication::srv::LdrData_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LdrData_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const LdrData_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LdrData_Event_

// alias to use template instance with default allocator
using LdrData_Event =
  milo_communication::srv::LdrData_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace milo_communication

namespace milo_communication
{

namespace srv
{

struct LdrData
{
  using Request = milo_communication::srv::LdrData_Request;
  using Response = milo_communication::srv::LdrData_Response;
  using Event = milo_communication::srv::LdrData_Event;
};

}  // namespace srv

}  // namespace milo_communication

#endif  // MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_HPP_
