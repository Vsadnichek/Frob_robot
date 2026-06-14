// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice

#include "frob_interfaces/msg/detail/obstacle_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_frob_interfaces
const rosidl_type_hash_t *
frob_interfaces__msg__ObstacleDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0xca, 0x68, 0x30, 0x91, 0x09, 0x7b, 0x60,
      0xc0, 0x6c, 0xb1, 0x84, 0x4e, 0x98, 0xbb, 0x08,
      0x40, 0xca, 0x3f, 0x59, 0xfd, 0xf7, 0xad, 0xcd,
      0xba, 0x77, 0xd4, 0x4f, 0x91, 0xe4, 0x32, 0x30,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char frob_interfaces__msg__ObstacleDetection__TYPE_NAME[] = "frob_interfaces/msg/ObstacleDetection";

// Define type names, field names, and default values
static char frob_interfaces__msg__ObstacleDetection__FIELD_NAME__blocked[] = "blocked";
static char frob_interfaces__msg__ObstacleDetection__FIELD_NAME__distance[] = "distance";
static char frob_interfaces__msg__ObstacleDetection__FIELD_NAME__zone_width[] = "zone_width";

static rosidl_runtime_c__type_description__Field frob_interfaces__msg__ObstacleDetection__FIELDS[] = {
  {
    {frob_interfaces__msg__ObstacleDetection__FIELD_NAME__blocked, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__ObstacleDetection__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__ObstacleDetection__FIELD_NAME__zone_width, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
frob_interfaces__msg__ObstacleDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {frob_interfaces__msg__ObstacleDetection__TYPE_NAME, 37, 37},
      {frob_interfaces__msg__ObstacleDetection__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool    blocked\n"
  "float32 distance\n"
  "float32 zone_width";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
frob_interfaces__msg__ObstacleDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {frob_interfaces__msg__ObstacleDetection__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 52, 52},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
frob_interfaces__msg__ObstacleDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *frob_interfaces__msg__ObstacleDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
