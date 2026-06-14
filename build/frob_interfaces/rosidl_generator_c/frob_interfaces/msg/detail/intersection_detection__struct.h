// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/intersection_detection.h"


#ifndef FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_H_
#define FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'NONE'.
enum
{
  frob_interfaces__msg__IntersectionDetection__NONE = 0
};

/// Constant 'T_LEFT'.
enum
{
  frob_interfaces__msg__IntersectionDetection__T_LEFT = 1
};

/// Constant 'T_RIGHT'.
enum
{
  frob_interfaces__msg__IntersectionDetection__T_RIGHT = 2
};

/// Constant 'T_FORWARD'.
enum
{
  frob_interfaces__msg__IntersectionDetection__T_FORWARD = 3
};

/// Constant 'CORNER_LEFT'.
enum
{
  frob_interfaces__msg__IntersectionDetection__CORNER_LEFT = 4
};

/// Constant 'CORNER_RIGHT'.
enum
{
  frob_interfaces__msg__IntersectionDetection__CORNER_RIGHT = 5
};

/// Constant 'CROSSROAD'.
enum
{
  frob_interfaces__msg__IntersectionDetection__CROSSROAD = 6
};

/// Struct defined in msg/IntersectionDetection in the package frob_interfaces.
typedef struct frob_interfaces__msg__IntersectionDetection
{
  uint8_t junction_type;
  float distance;
  bool detected;
} frob_interfaces__msg__IntersectionDetection;

// Struct for a sequence of frob_interfaces__msg__IntersectionDetection.
typedef struct frob_interfaces__msg__IntersectionDetection__Sequence
{
  frob_interfaces__msg__IntersectionDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__msg__IntersectionDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_H_
