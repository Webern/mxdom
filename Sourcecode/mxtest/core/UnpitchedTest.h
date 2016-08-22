// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"

namespace MxTestHelpers
{
    mx::core::UnpitchedPtr tgenUnpitched( variant v );
    void tgenUnpitchedExpected( std::ostream& os, int indentLevel, variant v );
}

#endif
