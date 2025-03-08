// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from milo_communication:srv/LdrData.idl
// generated code does not contain a copyright notice
#include "milo_communication/srv/detail/ldr_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
milo_communication__srv__LdrData_Request__init(milo_communication__srv__LdrData_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
milo_communication__srv__LdrData_Request__fini(milo_communication__srv__LdrData_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
milo_communication__srv__LdrData_Request__are_equal(const milo_communication__srv__LdrData_Request * lhs, const milo_communication__srv__LdrData_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
milo_communication__srv__LdrData_Request__copy(
  const milo_communication__srv__LdrData_Request * input,
  milo_communication__srv__LdrData_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

milo_communication__srv__LdrData_Request *
milo_communication__srv__LdrData_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Request * msg = (milo_communication__srv__LdrData_Request *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(milo_communication__srv__LdrData_Request));
  bool success = milo_communication__srv__LdrData_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
milo_communication__srv__LdrData_Request__destroy(milo_communication__srv__LdrData_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    milo_communication__srv__LdrData_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
milo_communication__srv__LdrData_Request__Sequence__init(milo_communication__srv__LdrData_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Request * data = NULL;

  if (size) {
    data = (milo_communication__srv__LdrData_Request *)allocator.zero_allocate(size, sizeof(milo_communication__srv__LdrData_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = milo_communication__srv__LdrData_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        milo_communication__srv__LdrData_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
milo_communication__srv__LdrData_Request__Sequence__fini(milo_communication__srv__LdrData_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      milo_communication__srv__LdrData_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

milo_communication__srv__LdrData_Request__Sequence *
milo_communication__srv__LdrData_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Request__Sequence * array = (milo_communication__srv__LdrData_Request__Sequence *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = milo_communication__srv__LdrData_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
milo_communication__srv__LdrData_Request__Sequence__destroy(milo_communication__srv__LdrData_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    milo_communication__srv__LdrData_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
milo_communication__srv__LdrData_Request__Sequence__are_equal(const milo_communication__srv__LdrData_Request__Sequence * lhs, const milo_communication__srv__LdrData_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!milo_communication__srv__LdrData_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
milo_communication__srv__LdrData_Request__Sequence__copy(
  const milo_communication__srv__LdrData_Request__Sequence * input,
  milo_communication__srv__LdrData_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(milo_communication__srv__LdrData_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    milo_communication__srv__LdrData_Request * data =
      (milo_communication__srv__LdrData_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!milo_communication__srv__LdrData_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          milo_communication__srv__LdrData_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!milo_communication__srv__LdrData_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
milo_communication__srv__LdrData_Response__init(milo_communication__srv__LdrData_Response * msg)
{
  if (!msg) {
    return false;
  }
  // lateral_ldr_intensities
  // forward_ldr_intensities
  return true;
}

void
milo_communication__srv__LdrData_Response__fini(milo_communication__srv__LdrData_Response * msg)
{
  if (!msg) {
    return;
  }
  // lateral_ldr_intensities
  // forward_ldr_intensities
}

bool
milo_communication__srv__LdrData_Response__are_equal(const milo_communication__srv__LdrData_Response * lhs, const milo_communication__srv__LdrData_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lateral_ldr_intensities
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->lateral_ldr_intensities[i] != rhs->lateral_ldr_intensities[i]) {
      return false;
    }
  }
  // forward_ldr_intensities
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->forward_ldr_intensities[i] != rhs->forward_ldr_intensities[i]) {
      return false;
    }
  }
  return true;
}

bool
milo_communication__srv__LdrData_Response__copy(
  const milo_communication__srv__LdrData_Response * input,
  milo_communication__srv__LdrData_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // lateral_ldr_intensities
  for (size_t i = 0; i < 4; ++i) {
    output->lateral_ldr_intensities[i] = input->lateral_ldr_intensities[i];
  }
  // forward_ldr_intensities
  for (size_t i = 0; i < 4; ++i) {
    output->forward_ldr_intensities[i] = input->forward_ldr_intensities[i];
  }
  return true;
}

milo_communication__srv__LdrData_Response *
milo_communication__srv__LdrData_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Response * msg = (milo_communication__srv__LdrData_Response *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(milo_communication__srv__LdrData_Response));
  bool success = milo_communication__srv__LdrData_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
milo_communication__srv__LdrData_Response__destroy(milo_communication__srv__LdrData_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    milo_communication__srv__LdrData_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
milo_communication__srv__LdrData_Response__Sequence__init(milo_communication__srv__LdrData_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Response * data = NULL;

  if (size) {
    data = (milo_communication__srv__LdrData_Response *)allocator.zero_allocate(size, sizeof(milo_communication__srv__LdrData_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = milo_communication__srv__LdrData_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        milo_communication__srv__LdrData_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
milo_communication__srv__LdrData_Response__Sequence__fini(milo_communication__srv__LdrData_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      milo_communication__srv__LdrData_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

milo_communication__srv__LdrData_Response__Sequence *
milo_communication__srv__LdrData_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Response__Sequence * array = (milo_communication__srv__LdrData_Response__Sequence *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = milo_communication__srv__LdrData_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
milo_communication__srv__LdrData_Response__Sequence__destroy(milo_communication__srv__LdrData_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    milo_communication__srv__LdrData_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
milo_communication__srv__LdrData_Response__Sequence__are_equal(const milo_communication__srv__LdrData_Response__Sequence * lhs, const milo_communication__srv__LdrData_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!milo_communication__srv__LdrData_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
milo_communication__srv__LdrData_Response__Sequence__copy(
  const milo_communication__srv__LdrData_Response__Sequence * input,
  milo_communication__srv__LdrData_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(milo_communication__srv__LdrData_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    milo_communication__srv__LdrData_Response * data =
      (milo_communication__srv__LdrData_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!milo_communication__srv__LdrData_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          milo_communication__srv__LdrData_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!milo_communication__srv__LdrData_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "milo_communication/srv/detail/ldr_data__functions.h"

bool
milo_communication__srv__LdrData_Event__init(milo_communication__srv__LdrData_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    milo_communication__srv__LdrData_Event__fini(msg);
    return false;
  }
  // request
  if (!milo_communication__srv__LdrData_Request__Sequence__init(&msg->request, 0)) {
    milo_communication__srv__LdrData_Event__fini(msg);
    return false;
  }
  // response
  if (!milo_communication__srv__LdrData_Response__Sequence__init(&msg->response, 0)) {
    milo_communication__srv__LdrData_Event__fini(msg);
    return false;
  }
  return true;
}

void
milo_communication__srv__LdrData_Event__fini(milo_communication__srv__LdrData_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  milo_communication__srv__LdrData_Request__Sequence__fini(&msg->request);
  // response
  milo_communication__srv__LdrData_Response__Sequence__fini(&msg->response);
}

bool
milo_communication__srv__LdrData_Event__are_equal(const milo_communication__srv__LdrData_Event * lhs, const milo_communication__srv__LdrData_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!milo_communication__srv__LdrData_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!milo_communication__srv__LdrData_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
milo_communication__srv__LdrData_Event__copy(
  const milo_communication__srv__LdrData_Event * input,
  milo_communication__srv__LdrData_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!milo_communication__srv__LdrData_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!milo_communication__srv__LdrData_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

milo_communication__srv__LdrData_Event *
milo_communication__srv__LdrData_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Event * msg = (milo_communication__srv__LdrData_Event *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(milo_communication__srv__LdrData_Event));
  bool success = milo_communication__srv__LdrData_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
milo_communication__srv__LdrData_Event__destroy(milo_communication__srv__LdrData_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    milo_communication__srv__LdrData_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
milo_communication__srv__LdrData_Event__Sequence__init(milo_communication__srv__LdrData_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Event * data = NULL;

  if (size) {
    data = (milo_communication__srv__LdrData_Event *)allocator.zero_allocate(size, sizeof(milo_communication__srv__LdrData_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = milo_communication__srv__LdrData_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        milo_communication__srv__LdrData_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
milo_communication__srv__LdrData_Event__Sequence__fini(milo_communication__srv__LdrData_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      milo_communication__srv__LdrData_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

milo_communication__srv__LdrData_Event__Sequence *
milo_communication__srv__LdrData_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  milo_communication__srv__LdrData_Event__Sequence * array = (milo_communication__srv__LdrData_Event__Sequence *)allocator.allocate(sizeof(milo_communication__srv__LdrData_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = milo_communication__srv__LdrData_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
milo_communication__srv__LdrData_Event__Sequence__destroy(milo_communication__srv__LdrData_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    milo_communication__srv__LdrData_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
milo_communication__srv__LdrData_Event__Sequence__are_equal(const milo_communication__srv__LdrData_Event__Sequence * lhs, const milo_communication__srv__LdrData_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!milo_communication__srv__LdrData_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
milo_communication__srv__LdrData_Event__Sequence__copy(
  const milo_communication__srv__LdrData_Event__Sequence * input,
  milo_communication__srv__LdrData_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(milo_communication__srv__LdrData_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    milo_communication__srv__LdrData_Event * data =
      (milo_communication__srv__LdrData_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!milo_communication__srv__LdrData_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          milo_communication__srv__LdrData_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!milo_communication__srv__LdrData_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
