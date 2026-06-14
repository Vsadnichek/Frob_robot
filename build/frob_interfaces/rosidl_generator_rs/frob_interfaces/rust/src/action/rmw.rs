
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Goal() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_Goal__init(msg: *mut ExecuteMotion_Goal) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Goal>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Goal>);
    fn frob_interfaces__action__ExecuteMotion_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Goal>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_Goal {
    /// "forward" or "rotate"
    pub command: rosidl_runtime_rs::String,

    /// distance in meters for forward, angle in radians for rotate
    pub value: f32,

}



impl Default for ExecuteMotion_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_Goal__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Goal() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Result() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_Result__init(msg: *mut ExecuteMotion_Result) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Result>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Result>);
    fn frob_interfaces__action__ExecuteMotion_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Result>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ExecuteMotion_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_Result__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_Result where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Result() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_Feedback__init(msg: *mut ExecuteMotion_Feedback) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Feedback>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Feedback>);
    fn frob_interfaces__action__ExecuteMotion_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_Feedback>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_Feedback {
    /// 0.0..1.0
    pub progress: f32,

}



impl Default for ExecuteMotion_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_Feedback__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_Feedback() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(msg: *mut ExecuteMotion_FeedbackMessage) -> bool;
    fn frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_FeedbackMessage>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_FeedbackMessage>);
    fn frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_FeedbackMessage>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ExecuteMotion_Feedback,

}



impl Default for ExecuteMotion_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_FeedbackMessage() }
  }
}




#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(msg: *mut ExecuteMotion_SendGoal_Request) -> bool;
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Request>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Request>);
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Request>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ExecuteMotion_Goal,

}



impl Default for ExecuteMotion_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal_Request() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(msg: *mut ExecuteMotion_SendGoal_Response) -> bool;
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Response>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Response>);
    fn frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_SendGoal_Response>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ExecuteMotion_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal_Response() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_GetResult_Request__init(msg: *mut ExecuteMotion_GetResult_Request) -> bool;
    fn frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Request>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Request>);
    fn frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Request>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ExecuteMotion_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult_Request() }
  }
}


#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "frob_interfaces__rosidl_generator_c")]
extern "C" {
    fn frob_interfaces__action__ExecuteMotion_GetResult_Response__init(msg: *mut ExecuteMotion_GetResult_Response) -> bool;
    fn frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Response>, size: usize) -> bool;
    fn frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Response>);
    fn frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMotion_GetResult_Response>) -> bool;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMotion_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ExecuteMotion_Result,

}



impl Default for ExecuteMotion_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !frob_interfaces__action__ExecuteMotion_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to frob_interfaces__action__ExecuteMotion_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMotion_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { frob_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMotion_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMotion_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "frob_interfaces/action/ExecuteMotion_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult_Response() }
  }
}






#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteMotion_SendGoal;

impl rosidl_runtime_rs::Service for ExecuteMotion_SendGoal {
    type Request = ExecuteMotion_SendGoal_Request;
    type Response = ExecuteMotion_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__action__ExecuteMotion_SendGoal() }
    }
}




#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__action__ExecuteMotion_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteMotion_GetResult;

impl rosidl_runtime_rs::Service for ExecuteMotion_GetResult {
    type Request = ExecuteMotion_GetResult_Request;
    type Response = ExecuteMotion_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__action__ExecuteMotion_GetResult() }
    }
}


