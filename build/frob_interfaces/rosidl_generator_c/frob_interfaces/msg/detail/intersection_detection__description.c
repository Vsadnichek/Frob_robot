// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

#include "frob_interfaces/msg/detail/intersection_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_frob_interfaces
const rosidl_type_hash_t *
frob_interfaces__msg__IntersectionDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0xb0, 0x96, 0x78, 0xd3, 0x4b, 0x82, 0xe3,
      0x48, 0xbb, 0xd3, 0xd6, 0xdd, 0x1e, 0x3c, 0x2d,
      0x93, 0x17, 0xfa, 0xe0, 0xae, 0x0d, 0x13, 0x9f,
      0x00, 0x94, 0xb5, 0x75, 0x1d, 0x74, 0x58, 0x52,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char frob_interfaces__msg__IntersectionDetection__TYPE_NAME[] = "frob_interfaces/msg/IntersectionDetection";

// Define type names, field names, and default values
static char frob_interfaces__msg__IntersectionDetection__FIELD_NAME__junction_type[] = "junction_type";
static char frob_interfaces__msg__IntersectionDetection__FIELD_NAME__distance[] = "distance";
static char frob_interfaces__msg__IntersectionDetection__FIELD_NAME__detected[] = "detected";

static rosidl_runtime_c__type_description__Field frob_interfaces__msg__IntersectionDetection__FIELDS[] = {
  {
    {frob_interfaces__msg__IntersectionDetection__FIELD_NAME__junction_type, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__IntersectionDetection__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__IntersectionDetection__FIELD_NAME__detected, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
frob_interfaces__msg__IntersectionDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {frob_interfaces__msg__IntersectionDetection__TYPE_NAME, 41, 41},
      {frob_interfaces__msg__IntersectionDetection__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 NONE=0\n"
  "uint8 T_LEFT=1\n"
  "uint8 T_RIGHT=2\n"
  "uint8 T_FORWARD=3\n"
  "uint8 CORNER_LEFT=4\n"
  "uint8 CORNER_RIGHT=5\n"
  "uint8 CROSSROAD=6\n"
  "\n"
  "uint8   junction_type\n"
  "float32 distance\n"
  "bool    detected";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
frob_interfaces__msg__IntersectionDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {frob_interfaces__msg__IntersectionDetection__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 178, 178},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
frob_interfaces__msg__IntersectionDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *frob_interfaces__msg__IntersectionDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
