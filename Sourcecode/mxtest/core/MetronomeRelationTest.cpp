// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mx/core/Elements.h"
#include <sstream>

using namespace mx::core;

TEST( Test01, MetronomeRelation )
{
	std::string indentString( INDENT );
	
	XsString value1{ "ABC" };
	XsString value2{ "XYZ" };
	
	MetronomeRelation object1;
	MetronomeRelation object2( value2 );
	
	std::stringstream default_constructed;
	object1.toStream( default_constructed, 0 );
	std::stringstream object2_stream;
	object2.toStream( object2_stream, 2 );
	
	std::string expected = R"(<metronome-relation>equals</metronome-relation>)";
	std::string actual = default_constructed.str();
	CHECK_EQUAL( expected, actual )
	
	expected = indentString+indentString+R"(<metronome-relation>XYZ</metronome-relation>)";
	actual = object2_stream.str();
	CHECK_EQUAL( expected, actual )
	
	value1 = object2.getValue();
	object1.setValue( value1 );

	std::stringstream o1;
	std::stringstream o2;
	bool isOneLineOnly = false;
	object1.streamContents( o1, 0, isOneLineOnly );
	object2.streamContents( o2, 0, isOneLineOnly );
	CHECK( isOneLineOnly )
	CHECK_EQUAL( o1.str(), o2.str() )
}

#endif
