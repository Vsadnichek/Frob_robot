#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Turn_Request() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__srv__Turn_Request__init(msg: *mut Turn_Request) -> bool;
    fn frob_interfaces__srv__Turn_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Turn_Request>, size: usize) -> bool;
    fn frob_interfaces__srv__Turn_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Turn_Request>);
    fn frob_interfaces__srv__Turn_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Turn_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Turn_Request>) -> bool;
}

// Corresponds to frob_interfaces__srv__Turn_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turn_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for Turn_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__srv__Turn_Request__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__srv__Turn_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Turn_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Turn_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Turn_Request where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/srv/Turn_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Turn_Request() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Turn_Response() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__srv__Turn_Response__init(msg: *mut Turn_Response) -> bool;
    fn frob_interfaces__srv__Turn_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Turn_Response>, size: usize) -> bool;
    fn frob_interfaces__srv__Turn_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Turn_Response>);
    fn frob_interfaces__srv__Turn_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Turn_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Turn_Response>) -> bool;
}

// Corresponds to frob_interfaces__srv__Turn_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turn_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Turn_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__srv__Turn_Response__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__srv__Turn_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Turn_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Turn_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Turn_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Turn_Response where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/srv/Turn_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Turn_Response() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Forward_Request() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__srv__Forward_Request__init(msg: *mut Forward_Request) -> bool;
    fn frob_interfaces__srv__Forward_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Forward_Request>, size: usize) -> bool;
    fn frob_interfaces__srv__Forward_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Forward_Request>);
    fn frob_interfaces__srv__Forward_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Forward_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Forward_Request>) -> bool;
}

// Corresponds to frob_interfaces__srv__Forward_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Forward_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub dist: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for Forward_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__srv__Forward_Request__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__srv__Forward_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Forward_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Forward_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Forward_Request where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/srv/Forward_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Forward_Request() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Forward_Response() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__srv__Forward_Response__init(msg: *mut Forward_Response) -> bool;
    fn frob_interfaces__srv__Forward_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Forward_Response>, size: usize) -> bool;
    fn frob_interfaces__srv__Forward_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Forward_Response>);
    fn frob_interfaces__srv__Forward_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Forward_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Forward_Response>) -> bool;
}

// Corresponds to frob_interfaces__srv__Forward_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Forward_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Forward_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__srv__Forward_Response__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__srv__Forward_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Forward_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__srv__Forward_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Forward_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Forward_Response where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/srv/Forward_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__srv__Forward_Response() }
  }
}






#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Turn() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__srv__Turn
#[allow(missing_docs, non_camel_case_types)]
pub struct Turn;

impl rosidl_runtime_rs::Service for Turn {
    type Request = Turn_Request;
    type Response = Turn_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Turn() }
    }
}




#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Forward() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__srv__Forward
#[allow(missing_docs, non_camel_case_types)]
pub struct Forward;

impl rosidl_runtime_rs::Service for Forward {
    type Request = Forward_Request;
    type Response = Forward_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Forward() }
    }
}


