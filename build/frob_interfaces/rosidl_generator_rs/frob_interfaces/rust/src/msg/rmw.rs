#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__LineDetection() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__msg__LineDetection__init(msg: *mut LineDetection) -> bool;
    fn frob_interfaces__msg__LineDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<LineDetection>, size: usize) -> bool;
    fn frob_interfaces__msg__LineDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<LineDetection>);
    fn frob_interfaces__msg__LineDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<LineDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<LineDetection>) -> bool;
}

// Corresponds to frob_interfaces__msg__LineDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LineDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lateral_error: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angle_error: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub line_center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub line_center_y: f32,

}



impl Default for LineDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__msg__LineDetection__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__msg__LineDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for LineDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__LineDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__LineDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__LineDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for LineDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for LineDetection where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/msg/LineDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__LineDetection() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__SignDetection() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__msg__SignDetection__init(msg: *mut SignDetection) -> bool;
    fn frob_interfaces__msg__SignDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SignDetection>, size: usize) -> bool;
    fn frob_interfaces__msg__SignDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SignDetection>);
    fn frob_interfaces__msg__SignDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SignDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<SignDetection>) -> bool;
}

// Corresponds to frob_interfaces__msg__SignDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SignDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sign_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_center_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height: f32,

}

impl SignDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_STRAIGHT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_LEFT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_RIGHT: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_LEFT_TURN: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_RIGHT_TURN: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BUS_STOP: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PARKING: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DANGER: u8 = 8;

}


impl Default for SignDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__msg__SignDetection__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__msg__SignDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SignDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__SignDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__SignDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__SignDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SignDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SignDetection where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/msg/SignDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__SignDetection() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__IntersectionDetection() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__msg__IntersectionDetection__init(msg: *mut IntersectionDetection) -> bool;
    fn frob_interfaces__msg__IntersectionDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IntersectionDetection>, size: usize) -> bool;
    fn frob_interfaces__msg__IntersectionDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IntersectionDetection>);
    fn frob_interfaces__msg__IntersectionDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IntersectionDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<IntersectionDetection>) -> bool;
}

// Corresponds to frob_interfaces__msg__IntersectionDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IntersectionDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub junction_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,

}

impl IntersectionDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NONE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_LEFT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_RIGHT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_FORWARD: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CORNER_LEFT: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CORNER_RIGHT: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CROSSROAD: u8 = 6;

}


impl Default for IntersectionDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__msg__IntersectionDetection__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__msg__IntersectionDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IntersectionDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__IntersectionDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__IntersectionDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__IntersectionDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IntersectionDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IntersectionDetection where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/msg/IntersectionDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__IntersectionDetection() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__ObstacleDetection() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__msg__ObstacleDetection__init(msg: *mut ObstacleDetection) -> bool;
    fn frob_interfaces__msg__ObstacleDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ObstacleDetection>, size: usize) -> bool;
    fn frob_interfaces__msg__ObstacleDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ObstacleDetection>);
    fn frob_interfaces__msg__ObstacleDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ObstacleDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<ObstacleDetection>) -> bool;
}

// Corresponds to frob_interfaces__msg__ObstacleDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObstacleDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub blocked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_width: f32,

}



impl Default for ObstacleDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__msg__ObstacleDetection__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__msg__ObstacleDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ObstacleDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__ObstacleDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__ObstacleDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__msg__ObstacleDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ObstacleDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ObstacleDetection where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/msg/ObstacleDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__msg__ObstacleDetection() }
  }
}


