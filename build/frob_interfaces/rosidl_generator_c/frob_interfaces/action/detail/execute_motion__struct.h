// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frob_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/action/execute_motion.h"


#ifndef FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_
#define FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_Goal
{
  /// "forward" or "rotate"
  rosidl_runtime_c__String command;
  /// distance in meters for forward, angle in radians for rotate
  float value;
} frob_interfaces__action__ExecuteMotion_Goal;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_Goal.
typedef struct frob_interfaces__action__ExecuteMotion_Goal__Sequence
{
  frob_interfaces__action__ExecuteMotion_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_Goal__Sequence;

// Constants defined in the message

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_Result
{
  bool success;
} frob_interfaces__action__ExecuteMotion_Result;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_Result.
typedef struct frob_interfaces__action__ExecuteMotion_Result__Sequence
{
  frob_interfaces__action__ExecuteMotion_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_Feedback
{
  /// 0.0..1.0
  float progress;
} frob_interfaces__action__ExecuteMotion_Feedback;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_Feedback.
typedef struct frob_interfaces__action__ExecuteMotion_Feedback__Sequence
{
  frob_interfaces__action__ExecuteMotion_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "frob_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  frob_interfaces__action__ExecuteMotion_Goal goal;
} frob_interfaces__action__ExecuteMotion_SendGoal_Request;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_SendGoal_Request.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence
{
  frob_interfaces__action__ExecuteMotion_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} frob_interfaces__action__ExecuteMotion_SendGoal_Response;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_SendGoal_Response.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence
{
  frob_interfaces__action__ExecuteMotion_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  frob_interfaces__action__ExecuteMotion_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  frob_interfaces__action__ExecuteMotion_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence request;
  frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence response;
} frob_interfaces__action__ExecuteMotion_SendGoal_Event;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_SendGoal_Event.
typedef struct frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence
{
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} frob_interfaces__action__ExecuteMotion_GetResult_Request;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_GetResult_Request.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence
{
  frob_interfaces__action__ExecuteMotion_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "frob_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Response
{
  int8_t status;
  frob_interfaces__action__ExecuteMotion_Result result;
} frob_interfaces__action__ExecuteMotion_GetResult_Response;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_GetResult_Response.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence
{
  frob_interfaces__action__ExecuteMotion_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  frob_interfaces__action__ExecuteMotion_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  frob_interfaces__action__ExecuteMotion_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence request;
  frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence response;
} frob_interfaces__action__ExecuteMotion_GetResult_Event;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_GetResult_Event.
typedef struct frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence
{
  frob_interfaces__action__ExecuteMotion_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "frob_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package frob_interfaces.
typedef struct frob_interfaces__action__ExecuteMotion_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  frob_interfaces__action__ExecuteMotion_Feedback feedback;
} frob_interfaces__action__ExecuteMotion_FeedbackMessage;

// Struct for a sequence of frob_interfaces__action__ExecuteMotion_FeedbackMessage.
typedef struct frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence
{
  frob_interfaces__action__ExecuteMotion_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_
