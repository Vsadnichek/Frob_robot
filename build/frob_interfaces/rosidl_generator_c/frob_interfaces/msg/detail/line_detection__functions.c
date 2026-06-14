// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/msg/detail/line_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
frob_interfaces__msg__LineDetection__init(frob_interfaces__msg__LineDetection * msg)
{
  if (!msg) {
    return false;
  }
  // detected
  // lateral_error
  // angle_error
  // confidence
  // line_center_x
  // line_center_y
  return true;
}

void
frob_interfaces__msg__LineDetection__fini(frob_interfaces__msg__LineDetection * msg)
{
  if (!msg) {
    return;
  }
  // detected
  // lateral_error
  // angle_error
  // confidence
  // line_center_x
  // line_center_y
}

bool
frob_interfaces__msg__LineDetection__are_equal(const frob_interfaces__msg__LineDetection * lhs, const frob_interfaces__msg__LineDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detected
  if (lhs->detected != rhs->detected) {
    return false;
  }
  // lateral_error
  if (lhs->lateral_error != rhs->lateral_error) {
    return false;
  }
  // angle_error
  if (lhs->angle_error != rhs->angle_error) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // line_center_x
  if (lhs->line_center_x != rhs->line_center_x) {
    return false;
  }
  // line_center_y
  if (lhs->line_center_y != rhs->line_center_y) {
    return false;
  }
  return true;
}

bool
frob_interfaces__msg__LineDetection__copy(
  const frob_interfaces__msg__LineDetection * input,
  frob_interfaces__msg__LineDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // detected
  output->detected = input->detected;
  // lateral_error
  output->lateral_error = input->lateral_error;
  // angle_error
  output->angle_error = input->angle_error;
  // confidence
  output->confidence = input->confidence;
  // line_center_x
  output->line_center_x = input->line_center_x;
  // line_center_y
  output->line_center_y = input->line_center_y;
  return true;
}

frob_interfaces__msg__LineDetection *
frob_interfaces__msg__LineDetection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__LineDetection * msg = (frob_interfaces__msg__LineDetection *)allocator.allocate(sizeof(frob_interfaces__msg__LineDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__msg__LineDetection));
  bool success = frob_interfaces__msg__LineDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__msg__LineDetection__destroy(frob_interfaces__msg__LineDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__msg__LineDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__msg__LineDetection__Sequence__init(frob_interfaces__msg__LineDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__LineDetection * data = NULL;

  if (size) {
    data = (frob_interfaces__msg__LineDetection *)allocator.zero_allocate(size, sizeof(frob_interfaces__msg__LineDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__msg__LineDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__msg__LineDetection__fini(&data[i - 1]);
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
frob_interfaces__msg__LineDetection__Sequence__fini(frob_interfaces__msg__LineDetection__Sequence * array)
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
      frob_interfaces__msg__LineDetection__fini(&array->data[i]);
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

frob_interfaces__msg__LineDetection__Sequence *
frob_interfaces__msg__LineDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__LineDetection__Sequence * array = (frob_interfaces__msg__LineDetection__Sequence *)allocator.allocate(sizeof(frob_interfaces__msg__LineDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__msg__LineDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__msg__LineDetection__Sequence__destroy(frob_interfaces__msg__LineDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__msg__LineDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__msg__LineDetection__Sequence__are_equal(const frob_interfaces__msg__LineDetection__Sequence * lhs, const frob_interfaces__msg__LineDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__msg__LineDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__msg__LineDetection__Sequence__copy(
  const frob_interfaces__msg__LineDetection__Sequence * input,
  frob_interfaces__msg__LineDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__msg__LineDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__msg__LineDetection * data =
      (frob_interfaces__msg__LineDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__msg__LineDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__msg__LineDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__msg__LineDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
