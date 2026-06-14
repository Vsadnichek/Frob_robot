// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice

#include "frob_interfaces/msg/detail/sign_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_frob_interfaces
const rosidl_type_hash_t *
frob_interfaces__msg__SignDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x85, 0x68, 0x7e, 0xa8, 0x14, 0x6e, 0xb4, 0x8d,
      0xf0, 0x2e, 0x29, 0x38, 0xd6, 0x3c, 0x00, 0x45,
      0x4c, 0x30, 0x46, 0xd1, 0x64, 0x9c, 0x26, 0x5a,
      0xb9, 0x4d, 0x9c, 0x6a, 0xaf, 0x03, 0xbb, 0xdb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char frob_interfaces__msg__SignDetection__TYPE_NAME[] = "frob_interfaces/msg/SignDetection";

// Define type names, field names, and default values
static char frob_interfaces__msg__SignDetection__FIELD_NAME__sign_type[] = "sign_type";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__distance[] = "distance";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__confidence[] = "confidence";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__detected[] = "detected";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_center_x[] = "bbox_center_x";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_center_y[] = "bbox_center_y";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_width[] = "bbox_width";
static char frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_height[] = "bbox_height";

static rosidl_runtime_c__type_description__Field frob_interfaces__msg__SignDetection__FIELDS[] = {
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__sign_type, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__detected, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_center_x, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_center_y, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_width, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {frob_interfaces__msg__SignDetection__FIELD_NAME__bbox_height, 11, 11},
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
frob_interfaces__msg__SignDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {frob_interfaces__msg__SignDetection__TYPE_NAME, 33, 33},
      {frob_interfaces__msg__SignDetection__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 UNKNOWN=0\n"
  "uint8 GO_STRAIGHT=1\n"
  "uint8 GO_LEFT=2\n"
  "uint8 GO_RIGHT=3\n"
  "uint8 NO_LEFT_TURN=4\n"
  "uint8 NO_RIGHT_TURN=5\n"
  "uint8 BUS_STOP=6\n"
  "uint8 PARKING=7\n"
  "uint8 DANGER=8\n"
  "\n"
  "uint8   sign_type\n"
  "float32 distance\n"
  "float32 confidence\n"
  "bool    detected\n"
  "float32 bbox_center_x\n"
  "float32 bbox_center_y\n"
  "float32 bbox_width\n"
  "float32 bbox_height";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
frob_interfaces__msg__SignDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {frob_interfaces__msg__SignDetection__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 315, 315},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
frob_interfaces__msg__SignDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *frob_interfaces__msg__SignDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
