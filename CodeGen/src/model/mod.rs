#[macro_use]
pub mod create;

pub mod builtin;
pub mod creator;
pub mod default_create;
pub mod enumeration;
pub mod post_process;
pub mod scalar;
pub mod symbol;
pub mod transform;

use crate::model::create::{Create, CreateError, CreateResult};
use crate::model::enumeration::Enumeration;
use crate::model::scalar::{ScalarNumeric, ScalarString};
use crate::model::symbol::Symbol;
use crate::xsd::restriction::Facet;
use crate::xsd::simple_type::{Payload, SimpleType};
use crate::xsd::{simple_type, Entry, Xsd};
pub use default_create::DefaultCreate;
use std::borrow::Borrow;
use std::ops::Deref;

#[derive(Debug, Clone, PartialEq, PartialOrd)]
pub enum Model {
    Enumeration(Enumeration),
    ScalarString(ScalarString),
    ScalarNumber(ScalarNumeric),
    CustomScalarString(ScalarString),
}
