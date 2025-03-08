// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "milo_communication/srv/detail/ldr_data__rosidl_typesupport_introspection_c.h"
#include "milo_communication/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "milo_communication/srv/detail/ldr_data__functions.h"
#include "milo_communication/srv/detail/ldr_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  milo_communication__srv__LdrData_Request__init(message_memory);
}

void milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_fini_function(void * message_memory)
{
  milo_communication__srv__LdrData_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_members = {
  "milo_communication__srv",  // message namespace
  "LdrData_Request",  // message name
  1,  // number of fields
  sizeof(milo_communication__srv__LdrData_Request),
  false,  // has_any_key_member_
  milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_member_array,  // message members
  milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle = {
  0,
  &milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_members,
  get_message_typesupport_handle_function,
  &milo_communication__srv__LdrData_Request__get_type_hash,
  &milo_communication__srv__LdrData_Request__get_type_description,
  &milo_communication__srv__LdrData_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_milo_communication
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Request)() {
  if (!milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle.typesupport_identifier) {
    milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "milo_communication/srv/detail/ldr_data__rosidl_typesupport_introspection_c.h"
// already included above
// #include "milo_communication/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "milo_communication/srv/detail/ldr_data__functions.h"
// already included above
// #include "milo_communication/srv/detail/ldr_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  milo_communication__srv__LdrData_Response__init(message_memory);
}

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_fini_function(void * message_memory)
{
  milo_communication__srv__LdrData_Response__fini(message_memory);
}

size_t milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__size_function__LdrData_Response__lateral_ldr_intensities(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__lateral_ldr_intensities(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__lateral_ldr_intensities(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__fetch_function__LdrData_Response__lateral_ldr_intensities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__lateral_ldr_intensities(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__assign_function__LdrData_Response__lateral_ldr_intensities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__lateral_ldr_intensities(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__size_function__LdrData_Response__forward_ldr_intensities(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__forward_ldr_intensities(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__forward_ldr_intensities(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__fetch_function__LdrData_Response__forward_ldr_intensities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__forward_ldr_intensities(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__assign_function__LdrData_Response__forward_ldr_intensities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__forward_ldr_intensities(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_member_array[2] = {
  {
    "lateral_ldr_intensities",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Response, lateral_ldr_intensities),  // bytes offset in struct
    NULL,  // default value
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__size_function__LdrData_Response__lateral_ldr_intensities,  // size() function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__lateral_ldr_intensities,  // get_const(index) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__lateral_ldr_intensities,  // get(index) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__fetch_function__LdrData_Response__lateral_ldr_intensities,  // fetch(index, &value) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__assign_function__LdrData_Response__lateral_ldr_intensities,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "forward_ldr_intensities",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Response, forward_ldr_intensities),  // bytes offset in struct
    NULL,  // default value
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__size_function__LdrData_Response__forward_ldr_intensities,  // size() function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_const_function__LdrData_Response__forward_ldr_intensities,  // get_const(index) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__get_function__LdrData_Response__forward_ldr_intensities,  // get(index) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__fetch_function__LdrData_Response__forward_ldr_intensities,  // fetch(index, &value) function pointer
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__assign_function__LdrData_Response__forward_ldr_intensities,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_members = {
  "milo_communication__srv",  // message namespace
  "LdrData_Response",  // message name
  2,  // number of fields
  sizeof(milo_communication__srv__LdrData_Response),
  false,  // has_any_key_member_
  milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_member_array,  // message members
  milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle = {
  0,
  &milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_members,
  get_message_typesupport_handle_function,
  &milo_communication__srv__LdrData_Response__get_type_hash,
  &milo_communication__srv__LdrData_Response__get_type_description,
  &milo_communication__srv__LdrData_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_milo_communication
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Response)() {
  if (!milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle.typesupport_identifier) {
    milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "milo_communication/srv/detail/ldr_data__rosidl_typesupport_introspection_c.h"
// already included above
// #include "milo_communication/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "milo_communication/srv/detail/ldr_data__functions.h"
// already included above
// #include "milo_communication/srv/detail/ldr_data__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "milo_communication/srv/ldr_data.h"
// Member `request`
// Member `response`
// already included above
// #include "milo_communication/srv/detail/ldr_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  milo_communication__srv__LdrData_Event__init(message_memory);
}

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_fini_function(void * message_memory)
{
  milo_communication__srv__LdrData_Event__fini(message_memory);
}

size_t milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__size_function__LdrData_Event__request(
  const void * untyped_member)
{
  const milo_communication__srv__LdrData_Request__Sequence * member =
    (const milo_communication__srv__LdrData_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__request(
  const void * untyped_member, size_t index)
{
  const milo_communication__srv__LdrData_Request__Sequence * member =
    (const milo_communication__srv__LdrData_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__request(
  void * untyped_member, size_t index)
{
  milo_communication__srv__LdrData_Request__Sequence * member =
    (milo_communication__srv__LdrData_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__fetch_function__LdrData_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const milo_communication__srv__LdrData_Request * item =
    ((const milo_communication__srv__LdrData_Request *)
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__request(untyped_member, index));
  milo_communication__srv__LdrData_Request * value =
    (milo_communication__srv__LdrData_Request *)(untyped_value);
  *value = *item;
}

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__assign_function__LdrData_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  milo_communication__srv__LdrData_Request * item =
    ((milo_communication__srv__LdrData_Request *)
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__request(untyped_member, index));
  const milo_communication__srv__LdrData_Request * value =
    (const milo_communication__srv__LdrData_Request *)(untyped_value);
  *item = *value;
}

bool milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__resize_function__LdrData_Event__request(
  void * untyped_member, size_t size)
{
  milo_communication__srv__LdrData_Request__Sequence * member =
    (milo_communication__srv__LdrData_Request__Sequence *)(untyped_member);
  milo_communication__srv__LdrData_Request__Sequence__fini(member);
  return milo_communication__srv__LdrData_Request__Sequence__init(member, size);
}

size_t milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__size_function__LdrData_Event__response(
  const void * untyped_member)
{
  const milo_communication__srv__LdrData_Response__Sequence * member =
    (const milo_communication__srv__LdrData_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__response(
  const void * untyped_member, size_t index)
{
  const milo_communication__srv__LdrData_Response__Sequence * member =
    (const milo_communication__srv__LdrData_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__response(
  void * untyped_member, size_t index)
{
  milo_communication__srv__LdrData_Response__Sequence * member =
    (milo_communication__srv__LdrData_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__fetch_function__LdrData_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const milo_communication__srv__LdrData_Response * item =
    ((const milo_communication__srv__LdrData_Response *)
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__response(untyped_member, index));
  milo_communication__srv__LdrData_Response * value =
    (milo_communication__srv__LdrData_Response *)(untyped_value);
  *value = *item;
}

void milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__assign_function__LdrData_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  milo_communication__srv__LdrData_Response * item =
    ((milo_communication__srv__LdrData_Response *)
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__response(untyped_member, index));
  const milo_communication__srv__LdrData_Response * value =
    (const milo_communication__srv__LdrData_Response *)(untyped_value);
  *item = *value;
}

bool milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__resize_function__LdrData_Event__response(
  void * untyped_member, size_t size)
{
  milo_communication__srv__LdrData_Response__Sequence * member =
    (milo_communication__srv__LdrData_Response__Sequence *)(untyped_member);
  milo_communication__srv__LdrData_Response__Sequence__fini(member);
  return milo_communication__srv__LdrData_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Event, request),  // bytes offset in struct
    NULL,  // default value
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__size_function__LdrData_Event__request,  // size() function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__request,  // get_const(index) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__request,  // get(index) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__fetch_function__LdrData_Event__request,  // fetch(index, &value) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__assign_function__LdrData_Event__request,  // assign(index, value) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__resize_function__LdrData_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(milo_communication__srv__LdrData_Event, response),  // bytes offset in struct
    NULL,  // default value
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__size_function__LdrData_Event__response,  // size() function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_const_function__LdrData_Event__response,  // get_const(index) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__get_function__LdrData_Event__response,  // get(index) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__fetch_function__LdrData_Event__response,  // fetch(index, &value) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__assign_function__LdrData_Event__response,  // assign(index, value) function pointer
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__resize_function__LdrData_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_members = {
  "milo_communication__srv",  // message namespace
  "LdrData_Event",  // message name
  3,  // number of fields
  sizeof(milo_communication__srv__LdrData_Event),
  false,  // has_any_key_member_
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_member_array,  // message members
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_type_support_handle = {
  0,
  &milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_members,
  get_message_typesupport_handle_function,
  &milo_communication__srv__LdrData_Event__get_type_hash,
  &milo_communication__srv__LdrData_Event__get_type_description,
  &milo_communication__srv__LdrData_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_milo_communication
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Event)() {
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Request)();
  milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Response)();
  if (!milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_type_support_handle.typesupport_identifier) {
    milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "milo_communication/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "milo_communication/srv/detail/ldr_data__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_members = {
  "milo_communication__srv",  // service namespace
  "LdrData",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle,
  NULL,  // response message
  // milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle
  NULL  // event_message
  // milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle
};


static rosidl_service_type_support_t milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_type_support_handle = {
  0,
  &milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_members,
  get_service_typesupport_handle_function,
  &milo_communication__srv__LdrData_Request__rosidl_typesupport_introspection_c__LdrData_Request_message_type_support_handle,
  &milo_communication__srv__LdrData_Response__rosidl_typesupport_introspection_c__LdrData_Response_message_type_support_handle,
  &milo_communication__srv__LdrData_Event__rosidl_typesupport_introspection_c__LdrData_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    milo_communication,
    srv,
    LdrData
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    milo_communication,
    srv,
    LdrData
  ),
  &milo_communication__srv__LdrData__get_type_hash,
  &milo_communication__srv__LdrData__get_type_description,
  &milo_communication__srv__LdrData__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_milo_communication
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData)(void) {
  if (!milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_type_support_handle.typesupport_identifier) {
    milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, milo_communication, srv, LdrData_Event)()->data;
  }

  return &milo_communication__srv__detail__ldr_data__rosidl_typesupport_introspection_c__LdrData_service_type_support_handle;
}
