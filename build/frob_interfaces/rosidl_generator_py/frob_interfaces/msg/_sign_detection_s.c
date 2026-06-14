// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from frob_interfaces:msg/SignDetection.idl
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
#include "frob_interfaces/msg/detail/sign_detection__struct.h"
#include "frob_interfaces/msg/detail/sign_detection__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool frob_interfaces__msg__sign_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("frob_interfaces.msg._sign_detection.SignDetection", full_classname_dest, 49) == 0);
  }
  frob_interfaces__msg__SignDetection * ros_message = _ros_message;
  {  // sign_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "sign_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sign_type = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // bbox_center_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_center_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_center_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_center_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_center_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_center_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_width");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_width = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_height = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * frob_interfaces__msg__sign_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SignDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("frob_interfaces.msg._sign_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SignDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  frob_interfaces__msg__SignDetection * ros_message = (frob_interfaces__msg__SignDetection *)raw_ros_message;
  {  // sign_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sign_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sign_type", field);
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
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_center_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_center_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_center_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_center_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_center_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_center_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_width
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
