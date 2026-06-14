# generated from rosidl_generator_py/resource/_idl.py.em
# with input from frob_interfaces:msg/LineDetection.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LineDetection(type):
    """Metaclass of message 'LineDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('frob_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'frob_interfaces.msg.LineDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__line_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__line_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__line_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__line_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__line_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LineDetection(metaclass=Metaclass_LineDetection):
    """Message class 'LineDetection'."""

    __slots__ = [
        '_detected',
        '_lateral_error',
        '_angle_error',
        '_confidence',
        '_line_center_x',
        '_line_center_y',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'detected': 'boolean',
        'lateral_error': 'float',
        'angle_error': 'float',
        'confidence': 'float',
        'line_center_x': 'float',
        'line_center_y': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.detected = kwargs.get('detected', bool())
        self.lateral_error = kwargs.get('lateral_error', float())
        self.angle_error = kwargs.get('angle_error', float())
        self.confidence = kwargs.get('confidence', float())
        self.line_center_x = kwargs.get('line_center_x', float())
        self.line_center_y = kwargs.get('line_center_y', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.detected != other.detected:
            return False
        if self.lateral_error != other.lateral_error:
            return False
        if self.angle_error != other.angle_error:
            return False
        if self.confidence != other.confidence:
            return False
        if self.line_center_x != other.line_center_x:
            return False
        if self.line_center_y != other.line_center_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def detected(self):
        """Message field 'detected'."""
        return self._detected

    @detected.setter
    def detected(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'detected' field must be of type 'bool'"
        self._detected = value

    @builtins.property
    def lateral_error(self):
        """Message field 'lateral_error'."""
        return self._lateral_error

    @lateral_error.setter
    def lateral_error(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'lateral_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lateral_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lateral_error = value

    @builtins.property
    def angle_error(self):
        """Message field 'angle_error'."""
        return self._angle_error

    @angle_error.setter
    def angle_error(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'angle_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'angle_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._angle_error = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def line_center_x(self):
        """Message field 'line_center_x'."""
        return self._line_center_x

    @line_center_x.setter
    def line_center_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'line_center_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'line_center_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._line_center_x = value

    @builtins.property
    def line_center_y(self):
        """Message field 'line_center_y'."""
        return self._line_center_y

    @line_center_y.setter
    def line_center_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'line_center_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'line_center_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._line_center_y = value
