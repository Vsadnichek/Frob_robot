// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/msg/detail/sign_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
frob_interfaces__msg__SignDetection__init(frob_interfaces__msg__SignDetection * msg)
{
  if (!msg) {
    return false;
  }
  // sign_type
  // distance
  // confidence
  // detected
  // bbox_center_x
  // bbox_center_y
  // bbox_width
  // bbox_height
  return true;
}

void
frob_interfaces__msg__SignDetection__fini(frob_interfaces__msg__SignDetection * msg)
{
  if (!msg) {
    return;
  }
  // sign_type
  // distance
  // confidence
  // detected
  // bbox_center_x
  // bbox_center_y
  // bbox_width
  // bbox_height
}

bool
frob_interfaces__msg__SignDetection__are_equal(const frob_interfaces__msg__SignDetection * lhs, const frob_interfaces__msg__SignDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sign_type
  if (lhs->sign_type != rhs->sign_type) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // detected
  if (lhs->detected != rhs->detected) {
    return false;
  }
  // bbox_center_x
  if (lhs->bbox_center_x != rhs->bbox_center_x) {
    return false;
  }
  // bbox_center_y
  if (lhs->bbox_center_y != rhs->bbox_center_y) {
    return false;
  }
  // bbox_width
  if (lhs->bbox_width != rhs->bbox_width) {
    return false;
  }
  // bbox_height
  if (lhs->bbox_height != rhs->bbox_height) {
    return false;
  }
  return true;
}

bool
frob_interfaces__msg__SignDetection__copy(
  const frob_interfaces__msg__SignDetection * input,
  frob_interfaces__msg__SignDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // sign_type
  output->sign_type = input->sign_type;
  // distance
  output->distance = input->distance;
  // confidence
  output->confidence = input->confidence;
  // detected
  output->detected = input->detected;
  // bbox_center_x
  output->bbox_center_x = input->bbox_center_x;
  // bbox_center_y
  output->bbox_center_y = input->bbox_center_y;
  // bbox_width
  output->bbox_width = input->bbox_width;
  // bbox_height
  output->bbox_height = input->bbox_height;
  return true;
}

frob_interfaces__msg__SignDetection *
frob_interfaces__msg__SignDetection__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__SignDetection * msg = (frob_interfaces__msg__SignDetection *)allocator.allocate(sizeof(frob_interfaces__msg__SignDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frob_interfaces__msg__SignDetection));
  bool success = frob_interfaces__msg__SignDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frob_interfaces__msg__SignDetection__destroy(frob_interfaces__msg__SignDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frob_interfaces__msg__SignDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frob_interfaces__msg__SignDetection__Sequence__init(frob_interfaces__msg__SignDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__SignDetection * data = NULL;

  if (size) {
    data = (frob_interfaces__msg__SignDetection *)allocator.zero_allocate(size, sizeof(frob_interfaces__msg__SignDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frob_interfaces__msg__SignDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frob_interfaces__msg__SignDetection__fini(&data[i - 1]);
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
frob_interfaces__msg__SignDetection__Sequence__fini(frob_interfaces__msg__SignDetection__Sequence * array)
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
      frob_interfaces__msg__SignDetection__fini(&array->data[i]);
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

frob_interfaces__msg__SignDetection__Sequence *
frob_interfaces__msg__SignDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frob_interfaces__msg__SignDetection__Sequence * array = (frob_interfaces__msg__SignDetection__Sequence *)allocator.allocate(sizeof(frob_interfaces__msg__SignDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frob_interfaces__msg__SignDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frob_interfaces__msg__SignDetection__Sequence__destroy(frob_interfaces__msg__SignDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frob_interfaces__msg__SignDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frob_interfaces__msg__SignDetection__Sequence__are_equal(const frob_interfaces__msg__SignDetection__Sequence * lhs, const frob_interfaces__msg__SignDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frob_interfaces__msg__SignDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frob_interfaces__msg__SignDetection__Sequence__copy(
  const frob_interfaces__msg__SignDetection__Sequence * input,
  frob_interfaces__msg__SignDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frob_interfaces__msg__SignDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frob_interfaces__msg__SignDetection * data =
      (frob_interfaces__msg__SignDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frob_interfaces__msg__SignDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frob_interfaces__msg__SignDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frob_interfaces__msg__SignDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
