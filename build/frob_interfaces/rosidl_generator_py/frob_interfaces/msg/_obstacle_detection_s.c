// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "frob_interfaces/msg/detail/obstacle_detection__struct.h"
#include "frob_interfaces/msg/detail/obstacle_detection__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool frob_interfaces__msg__obstacle_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("frob_interfaces.msg._obstacle_detection.ObstacleDetection", full_classname_dest, 57) == 0);
  }
  frob_interfaces__msg__ObstacleDetection * ros_message = _ros_message;
  {  // blocked
    PyObject * field = PyObject_GetAttrString(_pymsg, "blocked");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->blocked = (Py_True == field);
    Py_DECREF(field);
  }
  {  // distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // zone_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_width");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->zone_width = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * frob_interfaces__msg__obstacle_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ObstacleDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("frob_interfaces.msg._obstacle_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ObstacleDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  frob_interfaces__msg__ObstacleDetection * ros_message = (frob_interfaces__msg__ObstacleDetection *)raw_ros_message;
  {  // blocked
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->blocked ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blocked", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_width
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->zone_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
