# generated from rosidl_generator_py/resource/_idl.py.em
# with input from frob_interfaces:msg/SignDetection.idl
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


class Metaclass_SignDetection(type):
    """Metaclass of message 'SignDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'UNKNOWN': 0,
        'GO_STRAIGHT': 1,
        'GO_LEFT': 2,
        'GO_RIGHT': 3,
        'NO_LEFT_TURN': 4,
        'NO_RIGHT_TURN': 5,
        'BUS_STOP': 6,
        'PARKING': 7,
        'DANGER': 8,
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
                'frob_interfaces.msg.SignDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sign_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sign_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sign_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sign_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sign_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'GO_STRAIGHT': cls.__constants['GO_STRAIGHT'],
            'GO_LEFT': cls.__constants['GO_LEFT'],
            'GO_RIGHT': cls.__constants['GO_RIGHT'],
            'NO_LEFT_TURN': cls.__constants['NO_LEFT_TURN'],
            'NO_RIGHT_TURN': cls.__constants['NO_RIGHT_TURN'],
            'BUS_STOP': cls.__constants['BUS_STOP'],
            'PARKING': cls.__constants['PARKING'],
            'DANGER': cls.__constants['DANGER'],
        }

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_SignDetection.__constants['UNKNOWN']

    @property
    def GO_STRAIGHT(self):
        """Message constant 'GO_STRAIGHT'."""
        return Metaclass_SignDetection.__constants['GO_STRAIGHT']

    @property
    def GO_LEFT(self):
        """Message constant 'GO_LEFT'."""
        return Metaclass_SignDetection.__constants['GO_LEFT']

    @property
    def GO_RIGHT(self):
        """Message constant 'GO_RIGHT'."""
        return Metaclass_SignDetection.__constants['GO_RIGHT']

    @property
    def NO_LEFT_TURN(self):
        """Message constant 'NO_LEFT_TURN'."""
        return Metaclass_SignDetection.__constants['NO_LEFT_TURN']

    @property
    def NO_RIGHT_TURN(self):
        """Message constant 'NO_RIGHT_TURN'."""
        return Metaclass_SignDetection.__constants['NO_RIGHT_TURN']

    @property
    def BUS_STOP(self):
        """Message constant 'BUS_STOP'."""
        return Metaclass_SignDetection.__constants['BUS_STOP']

    @property
    def PARKING(self):
        """Message constant 'PARKING'."""
        return Metaclass_SignDetection.__constants['PARKING']

    @property
    def DANGER(self):
        """Message constant 'DANGER'."""
        return Metaclass_SignDetection.__constants['DANGER']


class SignDetection(metaclass=Metaclass_SignDetection):
    """
    Message class 'SignDetection'.

    Constants:
      UNKNOWN
      GO_STRAIGHT
      GO_LEFT
      GO_RIGHT
      NO_LEFT_TURN
      NO_RIGHT_TURN
      BUS_STOP
      PARKING
      DANGER
    """

    __slots__ = [
        '_sign_type',
        '_distance',
        '_confidence',
        '_detected',
        '_bbox_center_x',
        '_bbox_center_y',
        '_bbox_width',
        '_bbox_height',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'sign_type': 'uint8',
        'distance': 'float',
        'confidence': 'float',
        'detected': 'boolean',
        'bbox_center_x': 'float',
        'bbox_center_y': 'float',
        'bbox_width': 'float',
        'bbox_height': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.sign_type = kwargs.get('sign_type', int())
        self.distance = kwargs.get('distance', float())
        self.confidence = kwargs.get('confidence', float())
        self.detected = kwargs.get('detected', bool())
        self.bbox_center_x = kwargs.get('bbox_center_x', float())
        self.bbox_center_y = kwargs.get('bbox_center_y', float())
        self.bbox_width = kwargs.get('bbox_width', float())
        self.bbox_height = kwargs.get('bbox_height', float())

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
        if self.sign_type != other.sign_type:
            return False
        if self.distance != other.distance:
            return False
        if self.confidence != other.confidence:
            return False
        if self.detected != other.detected:
            return False
        if self.bbox_center_x != other.bbox_center_x:
            return False
        if self.bbox_center_y != other.bbox_center_y:
            return False
        if self.bbox_width != other.bbox_width:
            return False
        if self.bbox_height != other.bbox_height:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sign_type(self):
        """Message field 'sign_type'."""
        return self._sign_type

    @sign_type.setter
    def sign_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'sign_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sign_type' field must be an unsigned integer in [0, 255]"
        self._sign_type = value

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
    def bbox_center_x(self):
        """Message field 'bbox_center_x'."""
        return self._bbox_center_x

    @bbox_center_x.setter
    def bbox_center_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_center_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_center_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_center_x = value

    @builtins.property
    def bbox_center_y(self):
        """Message field 'bbox_center_y'."""
        return self._bbox_center_y

    @bbox_center_y.setter
    def bbox_center_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_center_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_center_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_center_y = value

    @builtins.property
    def bbox_width(self):
        """Message field 'bbox_width'."""
        return self._bbox_width

    @bbox_width.setter
    def bbox_width(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_width = value

    @builtins.property
    def bbox_height(self):
        """Message field 'bbox_height'."""
        return self._bbox_height

    @bbox_height.setter
    def bbox_height(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bbox_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_height = value
