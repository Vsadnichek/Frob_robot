# generated from rosidl_generator_py/resource/_idl.py.em
# with input from frob_interfaces:msg/IntersectionDetection.idl
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


class Metaclass_IntersectionDetection(type):
    """Metaclass of message 'IntersectionDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'NONE': 0,
        'T_LEFT': 1,
        'T_RIGHT': 2,
        'T_FORWARD': 3,
        'CORNER_LEFT': 4,
        'CORNER_RIGHT': 5,
        'CROSSROAD': 6,
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
                'frob_interfaces.msg.IntersectionDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__intersection_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__intersection_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__intersection_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__intersection_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__intersection_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'NONE': cls.__constants['NONE'],
            'T_LEFT': cls.__constants['T_LEFT'],
            'T_RIGHT': cls.__constants['T_RIGHT'],
            'T_FORWARD': cls.__constants['T_FORWARD'],
            'CORNER_LEFT': cls.__constants['CORNER_LEFT'],
            'CORNER_RIGHT': cls.__constants['CORNER_RIGHT'],
            'CROSSROAD': cls.__constants['CROSSROAD'],
        }

    @property
    def NONE(self):
        """Message constant 'NONE'."""
        return Metaclass_IntersectionDetection.__constants['NONE']

    @property
    def T_LEFT(self):
        """Message constant 'T_LEFT'."""
        return Metaclass_IntersectionDetection.__constants['T_LEFT']

    @property
    def T_RIGHT(self):
        """Message constant 'T_RIGHT'."""
        return Metaclass_IntersectionDetection.__constants['T_RIGHT']

    @property
    def T_FORWARD(self):
        """Message constant 'T_FORWARD'."""
        return Metaclass_IntersectionDetection.__constants['T_FORWARD']

    @property
    def CORNER_LEFT(self):
        """Message constant 'CORNER_LEFT'."""
        return Metaclass_IntersectionDetection.__constants['CORNER_LEFT']

    @property
    def CORNER_RIGHT(self):
        """Message constant 'CORNER_RIGHT'."""
        return Metaclass_IntersectionDetection.__constants['CORNER_RIGHT']

    @property
    def CROSSROAD(self):
        """Message constant 'CROSSROAD'."""
        return Metaclass_IntersectionDetection.__constants['CROSSROAD']


class IntersectionDetection(metaclass=Metaclass_IntersectionDetection):
    """
    Message class 'IntersectionDetection'.

    Constants:
      NONE
      T_LEFT
      T_RIGHT
      T_FORWARD
      CORNER_LEFT
      CORNER_RIGHT
      CROSSROAD
    """

    __slots__ = [
        '_junction_type',
        '_distance',
        '_detected',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'junction_type': 'uint8',
        'distance': 'float',
        'detected': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.junction_type = kwargs.get('junction_type', int())
        self.distance = kwargs.get('distance', float())
        self.detected = kwargs.get('detected', bool())

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
        if self.junction_type != other.junction_type:
            return False
        if self.distance != other.distance:
            return False
        if self.detected != other.detected:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def junction_type(self):
        """Message field 'junction_type'."""
        return self._junction_type

    @junction_type.setter
    def junction_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'junction_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'junction_type' field must be an unsigned integer in [0, 255]"
        self._junction_type = value

    @builtins.property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance = value

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
