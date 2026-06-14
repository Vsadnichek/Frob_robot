// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/obstacle_detection.h"


#ifndef FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_H_
#define FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ObstacleDetection in the package frob_interfaces.
typedef struct frob_interfaces__msg__ObstacleDetection
{
  bool blocked;
  float distance;
  float zone_width;
} frob_interfaces__msg__ObstacleDetection;

// Struct for a sequence of frob_interfaces__msg__ObstacleDetection.
typedef struct frob_interfaces__msg__ObstacleDetection__Sequence
{
  frob_interfaces__msg__ObstacleDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__msg__ObstacleDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_H_
