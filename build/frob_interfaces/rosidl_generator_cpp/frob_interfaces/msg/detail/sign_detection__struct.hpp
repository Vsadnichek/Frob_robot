// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/sign_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_HPP_
#define FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__frob_interfaces__msg__SignDetection __attribute__((deprecated))
#else
# define DEPRECATED__frob_interfaces__msg__SignDetection __declspec(deprecated)
#endif

namespace frob_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SignDetection_
{
  using Type = SignDetection_<ContainerAllocator>;

  explicit SignDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sign_type = 0;
      this->distance = 0.0f;
      this->confidence = 0.0f;
      this->detected = false;
      this->bbox_center_x = 0.0f;
      this->bbox_center_y = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
    }
  }

  explicit SignDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sign_type = 0;
      this->distance = 0.0f;
      this->confidence = 0.0f;
      this->detected = false;
      this->bbox_center_x = 0.0f;
      this->bbox_center_y = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
    }
  }

  // field types and members
  using _sign_type_type =
    uint8_t;
  _sign_type_type sign_type;
  using _distance_type =
    float;
  _distance_type distance;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _detected_type =
    bool;
  _detected_type detected;
  using _bbox_center_x_type =
    float;
  _bbox_center_x_type bbox_center_x;
  using _bbox_center_y_type =
    float;
  _bbox_center_y_type bbox_center_y;
  using _bbox_width_type =
    float;
  _bbox_width_type bbox_width;
  using _bbox_height_type =
    float;
  _bbox_height_type bbox_height;

  // setters for named parameter idiom
  Type & set__sign_type(
    const uint8_t & _arg)
  {
    this->sign_type = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__bbox_center_x(
    const float & _arg)
  {
    this->bbox_center_x = _arg;
    return *this;
  }
  Type & set__bbox_center_y(
    const float & _arg)
  {
    this->bbox_center_y = _arg;
    return *this;
  }
  Type & set__bbox_width(
    const float & _arg)
  {
    this->bbox_width = _arg;
    return *this;
  }
  Type & set__bbox_height(
    const float & _arg)
  {
    this->bbox_height = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t UNKNOWN =
    0u;
  static constexpr uint8_t GO_STRAIGHT =
    1u;
  static constexpr uint8_t GO_LEFT =
    2u;
  static constexpr uint8_t GO_RIGHT =
    3u;
  static constexpr uint8_t NO_LEFT_TURN =
    4u;
  static constexpr uint8_t NO_RIGHT_TURN =
    5u;
  static constexpr uint8_t BUS_STOP =
    6u;
  static constexpr uint8_t PARKING =
    7u;
  static constexpr uint8_t DANGER =
    8u;

  // pointer types
  using RawPtr =
    frob_interfaces::msg::SignDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const frob_interfaces::msg::SignDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::SignDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::SignDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__frob_interfaces__msg__SignDetection
    std::shared_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__frob_interfaces__msg__SignDetection
    std::shared_ptr<frob_interfaces::msg::SignDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SignDetection_ & other) const
  {
    if (this->sign_type != other.sign_type) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->detected != other.detected) {
      return false;
    }
    if (this->bbox_center_x != other.bbox_center_x) {
      return false;
    }
    if (this->bbox_center_y != other.bbox_center_y) {
      return false;
    }
    if (this->bbox_width != other.bbox_width) {
      return false;
    }
    if (this->bbox_height != other.bbox_height) {
      return false;
    }
    return true;
  }
  bool operator!=(const SignDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SignDetection_

// alias to use template instance with default allocator
using SignDetection =
  frob_interfaces::msg::SignDetection_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::GO_STRAIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::GO_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::GO_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::NO_LEFT_TURN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::NO_RIGHT_TURN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::BUS_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::PARKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SignDetection_<ContainerAllocator>::DANGER;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__STRUCT_HPP_
