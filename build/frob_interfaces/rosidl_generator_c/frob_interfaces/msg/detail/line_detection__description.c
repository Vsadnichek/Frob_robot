// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice

#include "frob_interfaces/msg/detail/line_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_frob_interfaces
const rosidl_type_hash_t *
frob_interfaces__msg__LineDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0x0a, 0xf5, 0x49, 0xdf, 0xc9, 0x9d, 0x1a,
      0xdc, 0x3b, 0xcc, 0xfb, 0x80, 0xf3, 0x44, 0x41,
      0x89, 0x03, 0x08, 0xa6, 0x0e, 0x35, 0x70, 0x97,
      0x61, 0xb9, 0x8e, 0x48, 0x01, 0x93, 0xf3, 0x9a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char frob_interfaces__msg__LineDetection__TYPE_NAME[] = "frob_interfaces/msg/LineDetection";

// Define type names, field names, and default values
static char frob_interfaces__msg__LineDetection__FIELD_NAME__detected[] = "detected";
static char frob_interfaces__msg__LineDetection__FIELD_NAME__lateral_error[] = "lateral_error";
static char frob_interfaces__msg__LineDetection__FIELD_NAME__angle_error[] = "angle_error";
static char frob_interfaces__msg__LineDetection__FIELD_NAME__confidence[] = "confidence";
static char frob_interfaces__msg__LineDetection__FIELD_NAME__line_center_x[] = "line_center_x";
static char frob_interfaces__msg__LineDetection__FIELD_NAME__line_center_y[] = "line_center_y";

static rosidl_runtime_c__type_description__Field frob_interfaces__msg__LineDetection__FIELDS[] = {
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__detected, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__lateral_error, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__angle_error, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__line_center_x, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__LineDetection__FIELD_NAME__line_center_y, 13, 13},
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
frob_interfaces__msg__LineDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {frob_interfaces__msg__LineDetection__TYPE_NAME, 33, 33},
      {frob_interfaces__msg__LineDetection__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool    detected\n"
  "float32 lateral_error\n"
  "float32 angle_error\n"
  "float32 confidence\n"
  "float32 line_center_x\n"
  "float32 line_center_y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
frob_interfaces__msg__LineDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {frob_interfaces__msg__LineDetection__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 122, 122},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
frob_interfaces__msg__LineDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *frob_interfaces__msg__LineDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
