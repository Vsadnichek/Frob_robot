// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/sign_detection.h"


#ifndef FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_H_
#define FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'UNKNOWN'.
enum
{
  frob_interfaces__msg__SignDetection__UNKNOWN = 0
};

/// Constant 'GO_STRAIGHT'.
enum
{
  frob_interfaces__msg__SignDetection__GO_STRAIGHT = 1
};

/// Constant 'GO_LEFT'.
enum
{
  frob_interfaces__msg__SignDetection__GO_LEFT = 2
};

/// Constant 'GO_RIGHT'.
enum
{
  frob_interfaces__msg__SignDetection__GO_RIGHT = 3
};

/// Constant 'NO_LEFT_TURN'.
enum
{
  frob_interfaces__msg__SignDetection__NO_LEFT_TURN = 4
};

/// Constant 'NO_RIGHT_TURN'.
enum
{
  frob_interfaces__msg__SignDetection__NO_RIGHT_TURN = 5
};

/// Constant 'BUS_STOP'.
enum
{
  frob_interfaces__msg__SignDetection__BUS_STOP = 6
};

/// Constant 'PARKING'.
enum
{
  frob_interfaces__msg__SignDetection__PARKING = 7
};

/// Constant 'DANGER'.
enum
{
  frob_interfaces__msg__SignDetection__DANGER = 8
};

/// Struct defined in msg/SignDetection in the package frob_interfaces.
typedef struct frob_interfaces__msg__SignDetection
{
  uint8_t sign_type;
  float distance;
  float confidence;
  bool detected;
  float bbox_center_x;
  float bbox_center_y;
  float bbox_width;
  float bbox_height;
} frob_interfaces__msg__SignDetection;

// Struct for a sequence of frob_interfaces__msg__SignDetection.
typedef struct frob_interfaces__msg__SignDetection__Sequence
{
  frob_interfaces__msg__SignDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__msg__SignDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_H_
