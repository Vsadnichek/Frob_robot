// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/line_detection.h"


#ifndef FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_H_
#define FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/LineDetection in the package frob_interfaces.
typedef struct frob_interfaces__msg__LineDetection
{
  bool detected;
  float lateral_error;
  float angle_error;
  float confidence;
  float line_center_x;
  float line_center_y;
} frob_interfaces__msg__LineDetection;

// Struct for a sequence of frob_interfaces__msg__LineDetection.
typedef struct frob_interfaces__msg__LineDetection__Sequence
{
  frob_interfaces__msg__LineDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__msg__LineDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_H_
