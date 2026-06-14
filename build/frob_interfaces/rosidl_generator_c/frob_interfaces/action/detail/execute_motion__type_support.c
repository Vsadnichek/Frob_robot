// generated from rosidl_generator_c/resource/idl__type_support.c.em
// with input from frob_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice

#include <string.h>

#include "frob_interfaces/action/detail/execute_motion__type_support.h"
#include "rosidl_typesupport_interface/macros.h"
#include "frob_interfaces/action/detail/execute_motion__struct.h"
#include "frob_interfaces/action/detail/execute_motion__functions.h"

#ifdef __cplusplus
extern "C"
{
#endif


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  frob_interfaces,
  action,
  ExecuteMotion_SendGoal
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * event_msg = (frob_interfaces__action__ExecuteMotion_SendGoal_Event *)(allocator->allocate(sizeof(frob_interfaces__action__ExecuteMotion_SendGoal_Event), allocator->state));
  if (!frob_interfaces__action__ExecuteMotion_SendGoal_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Request__copy((const frob_interfaces__action__ExecuteMotion_SendGoal_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!frob_interfaces__action__ExecuteMotion_SendGoal_Response__copy((const frob_interfaces__action__ExecuteMotion_SendGoal_Response *)(response_message), event_msg->response.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  return event_msg;
}

// Forward declare the get type support functions for this type.
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  frob_interfaces,
  action,
  ExecuteMotion_SendGoal
)(
  void * event_msg,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    return false;
  }
  if (NULL == event_msg) {
    return false;
  }
  frob_interfaces__action__ExecuteMotion_SendGoal_Event * _event_msg = (frob_interfaces__action__ExecuteMotion_SendGoal_Event *)(event_msg);

  frob_interfaces__action__ExecuteMotion_SendGoal_Event__fini((frob_interfaces__action__ExecuteMotion_SendGoal_Event *)(_event_msg));
  if (_event_msg->request.data) {
    allocator->deallocate(_event_msg->request.data, allocator->state);
  }
  if (_event_msg->response.data) {
    allocator->deallocate(_event_msg->response.data, allocator->state);
  }
  allocator->deallocate(_event_msg, allocator->state);
  return true;
}


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  frob_interfaces,
  action,
  ExecuteMotion_GetResult
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  frob_interfaces__action__ExecuteMotion_GetResult_Event * event_msg = (frob_interfaces__action__ExecuteMotion_GetResult_Event *)(allocator->allocate(sizeof(frob_interfaces__action__ExecuteMotion_GetResult_Event), allocator->state));
  if (!frob_interfaces__action__ExecuteMotion_GetResult_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Request__copy((const frob_interfaces__action__ExecuteMotion_GetResult_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!frob_interfaces__action__ExecuteMotion_GetResult_Response__copy((const frob_interfaces__action__ExecuteMotion_GetResult_Response *)(response_message), event_msg->response.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  return event_msg;
}

// Forward declare the get type support functions for this type.
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  frob_interfaces,
  action,
  ExecuteMotion_GetResult
)(
  void * event_msg,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    return false;
  }
  if (NULL == event_msg) {
    return false;
  }
  frob_interfaces__action__ExecuteMotion_GetResult_Event * _event_msg = (frob_interfaces__action__ExecuteMotion_GetResult_Event *)(event_msg);

  frob_interfaces__action__ExecuteMotion_GetResult_Event__fini((frob_interfaces__action__ExecuteMotion_GetResult_Event *)(_event_msg));
  if (_event_msg->request.data) {
    allocator->deallocate(_event_msg->request.data, allocator->state);
  }
  if (_event_msg->response.data) {
    allocator->deallocate(_event_msg->response.data, allocator->state);
  }
  allocator->deallocate(_event_msg, allocator->state);
  return true;
}

#ifdef __cplusplus
}
#endif
