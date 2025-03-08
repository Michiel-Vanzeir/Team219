// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "milo_communication/srv/ldr_data.h"


#ifndef MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_H_
#define MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/LdrData in the package milo_communication.
typedef struct milo_communication__srv__LdrData_Request
{
  uint8_t structure_needs_at_least_one_member;
} milo_communication__srv__LdrData_Request;

// Struct for a sequence of milo_communication__srv__LdrData_Request.
typedef struct milo_communication__srv__LdrData_Request__Sequence
{
  milo_communication__srv__LdrData_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} milo_communication__srv__LdrData_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/LdrData in the package milo_communication.
typedef struct milo_communication__srv__LdrData_Response
{
  float lateral_ldr_intensities[4];
  float forward_ldr_intensities[4];
} milo_communication__srv__LdrData_Response;

// Struct for a sequence of milo_communication__srv__LdrData_Response.
typedef struct milo_communication__srv__LdrData_Response__Sequence
{
  milo_communication__srv__LdrData_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} milo_communication__srv__LdrData_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  milo_communication__srv__LdrData_Event__request__MAX_SIZE = 1
};
// response
enum
{
  milo_communication__srv__LdrData_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/LdrData in the package milo_communication.
typedef struct milo_communication__srv__LdrData_Event
{
  service_msgs__msg__ServiceEventInfo info;
  milo_communication__srv__LdrData_Request__Sequence request;
  milo_communication__srv__LdrData_Response__Sequence response;
} milo_communication__srv__LdrData_Event;

// Struct for a sequence of milo_communication__srv__LdrData_Event.
typedef struct milo_communication__srv__LdrData_Event__Sequence
{
  milo_communication__srv__LdrData_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} milo_communication__srv__LdrData_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MILO_COMMUNICATION__SRV__DETAIL__LDR_DATA__STRUCT_H_
