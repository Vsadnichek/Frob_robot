// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from frob_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/action/detail/execute_motion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
frob_interfaces__action__ExecuteMotion_Goal__init(frob_interfaces__action__ExecuteMotion_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    frob_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // value
  return true;
}

void
frob_interfaces__action__ExecuteMotion_Goal__fini(frob_interfaces__action__ExecuteMotion_Goal * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // value
}

bool
frob_interfaces__action__ExecuteMotion_Goal__are_equal(const frob_interfaces__action__ExecuteMotion_Goal * lhs, const frob_interfaces__action__ExecuteMotion_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Goal__copy(
  const frob_interfaces__action__ExecuteMotion_Goal * input,
  frob_interfaces__action__ExecuteMotion_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // value
  output->value = input->value;
  return true;
}

frob_interfaces__action__ExecuteMotion_Goal *
frob_interfaces__action__ExecuteMotion_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Goal * msg = (frob_interfaces__action__ExecuteMotion_Goal *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_Goal));
  bool success = frob_interfaces__action__ExecuteMotion_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_Goal__destroy(frob_interfaces__action__ExecuteMotion_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_Goal__Sequence__init(frob_interfaces__action__ExecuteMotion_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Goal * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_Goal *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_Goal__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_Goal__Sequence__fini(frob_interfaces__action__ExecuteMotion_Goal__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_Goal__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_Goal__Sequence *
frob_interfaces__action__ExecuteMotion_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Goal__Sequence * array = (frob_interfaces__action__ExecuteMotion_Goal__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_Goal__Sequence__destroy(frob_interfaces__action__ExecuteMotion_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_Goal__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_Goal__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Goal__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_Goal__Sequence * input,
  frob_interfaces__action__ExecuteMotion_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_Goal * data =
      (frob_interfaces__action__ExecuteMotion_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
frob_interfaces__action__ExecuteMotion_Result__init(frob_interfaces__action__ExecuteMotion_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
frob_interfaces__action__ExecuteMotion_Result__fini(frob_interfaces__action__ExecuteMotion_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
frob_interfaces__action__ExecuteMotion_Result__are_equal(const frob_interfaces__action__ExecuteMotion_Result * lhs, const frob_interfaces__action__ExecuteMotion_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Result__copy(
  const frob_interfaces__action__ExecuteMotion_Result * input,
  frob_interfaces__action__ExecuteMotion_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

frob_interfaces__action__ExecuteMotion_Result *
frob_interfaces__action__ExecuteMotion_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Result * msg = (frob_interfaces__action__ExecuteMotion_Result *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_Result));
  bool success = frob_interfaces__action__ExecuteMotion_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_Result__destroy(frob_interfaces__action__ExecuteMotion_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_Result__Sequence__init(frob_interfaces__action__ExecuteMotion_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Result * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_Result *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_Result__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_Result__Sequence__fini(frob_interfaces__action__ExecuteMotion_Result__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_Result__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_Result__Sequence *
frob_interfaces__action__ExecuteMotion_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Result__Sequence * array = (frob_interfaces__action__ExecuteMotion_Result__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_Result__Sequence__destroy(frob_interfaces__action__ExecuteMotion_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_Result__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_Result__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Result__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_Result__Sequence * input,
  frob_interfaces__action__ExecuteMotion_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_Result * data =
      (frob_interfaces__action__ExecuteMotion_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
frob_interfaces__action__ExecuteMotion_Feedback__init(frob_interfaces__action__ExecuteMotion_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  return true;
}

void
frob_interfaces__action__ExecuteMotion_Feedback__fini(frob_interfaces__action__ExecuteMotion_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
}

bool
frob_interfaces__action__ExecuteMotion_Feedback__are_equal(const frob_interfaces__action__ExecuteMotion_Feedback * lhs, const frob_interfaces__action__ExecuteMotion_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Feedback__copy(
  const frob_interfaces__action__ExecuteMotion_Feedback * input,
  frob_interfaces__action__ExecuteMotion_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

frob_interfaces__action__ExecuteMotion_Feedback *
frob_interfaces__action__ExecuteMotion_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Feedback * msg = (frob_interfaces__action__ExecuteMotion_Feedback *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_Feedback));
  bool success = frob_interfaces__action__ExecuteMotion_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_Feedback__destroy(frob_interfaces__action__ExecuteMotion_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__init(frob_interfaces__action__ExecuteMotion_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Feedback * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_Feedback *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_Feedback__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(frob_interfaces__action__ExecuteMotion_Feedback__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_Feedback__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_Feedback__Sequence *
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_Feedback__Sequence * array = (frob_interfaces__action__ExecuteMotion_Feedback__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__destroy(frob_interfaces__action__ExecuteMotion_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_Feedback__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_Feedback__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_Feedback__Sequence * input,
  frob_interfaces__action__ExecuteMotion_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_Feedback * data =
      (frob_interfaces__action__ExecuteMotion_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "frob_interfaces/action/detail/execute_motion__functions.h"

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(frob_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!frob_interfaces__action__ExecuteMotion_Goal__init(&msg->goal)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  frob_interfaces__action__ExecuteMotion_Goal__fini(&msg->goal);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Request * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!frob_interfaces__action__ExecuteMotion_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Request * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!frob_interfaces__action__ExecuteMotion_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_SendGoal_Request *
frob_interfaces__action__ExecuteMotion_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Request * msg = (frob_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Request));
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Request__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Request * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence *
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array = (frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_SendGoal_Request * data =
      (frob_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(frob_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Response * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Response * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_SendGoal_Response *
frob_interfaces__action__ExecuteMotion_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Response * msg = (frob_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Response));
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Response__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Response * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence *
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array = (frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_SendGoal_Response * data =
      (frob_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__copy(
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
// #include "frob_interfaces/action/detail/execute_motion__functions.h"

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__init(frob_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Event * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Event * rhs)
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
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Event * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * output)
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
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_SendGoal_Event *
frob_interfaces__action__ExecuteMotion_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * msg = (frob_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event));
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Event__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__init(frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__fini(frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence *
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array = (frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__destroy(frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * input,
  frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_SendGoal_Event * data =
      (frob_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__init(frob_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(frob_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Request * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Request * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_GetResult_Request *
frob_interfaces__action__ExecuteMotion_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Request * msg = (frob_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Request));
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Request__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Request * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence *
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array = (frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_GetResult_Request * data =
      (frob_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "frob_interfaces/action/detail/execute_motion__functions.h"

bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__init(frob_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!frob_interfaces__action__ExecuteMotion_Result__init(&msg->result)) {
    frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(frob_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  frob_interfaces__action__ExecuteMotion_Result__fini(&msg->result);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Response * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!frob_interfaces__action__ExecuteMotion_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Response * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!frob_interfaces__action__ExecuteMotion_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_GetResult_Response *
frob_interfaces__action__ExecuteMotion_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Response * msg = (frob_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Response));
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Response__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Response * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence *
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array = (frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_GetResult_Response * data =
      (frob_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "frob_interfaces/action/detail/execute_motion__functions.h"

bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__init(frob_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(&msg->request, 0)) {
    frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(&msg->response, 0)) {
    frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(frob_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(&msg->request);
  // response
  frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(&msg->response);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Event * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Event * rhs)
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
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Event * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Event * output)
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
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_GetResult_Event *
frob_interfaces__action__ExecuteMotion_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Event * msg = (frob_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event));
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Event__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__init(frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Event * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__fini(frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence *
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array = (frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__destroy(frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * input,
  frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_GetResult_Event * data =
      (frob_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "frob_interfaces/action/detail/execute_motion__functions.h"

bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(frob_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!frob_interfaces__action__ExecuteMotion_Feedback__init(&msg->feedback)) {
    frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(frob_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  frob_interfaces__action__ExecuteMotion_Feedback__fini(&msg->feedback);
}

bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__are_equal(const frob_interfaces__action__ExecuteMotion_FeedbackMessage * lhs, const frob_interfaces__action__ExecuteMotion_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!frob_interfaces__action__ExecuteMotion_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__copy(
  const frob_interfaces__action__ExecuteMotion_FeedbackMessage * input,
  frob_interfaces__action__ExecuteMotion_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!frob_interfaces__action__ExecuteMotion_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

frob_interfaces__action__ExecuteMotion_FeedbackMessage *
frob_interfaces__action__ExecuteMotion_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_FeedbackMessage * msg = (frob_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__action__ExecuteMotion_FeedbackMessage));
  bool success = frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__action__ExecuteMotion_FeedbackMessage__destroy(frob_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_FeedbackMessage * data = NULL;

  if (size) {
    data = (frob_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.zero_allocate(size, sizeof(frob_interfaces__action__ExecuteMotion_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&data[i - 1]);
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
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array)
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
      frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&array->data[i]);
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

frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence *
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array = (frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence *)allocator.allocate(sizeof(frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__destroy(frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__are_equal(const frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * lhs, const frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__copy(
  const frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * input,
  frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__action__ExecuteMotion_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__action__ExecuteMotion_FeedbackMessage * data =
      (frob_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__action__ExecuteMotion_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
