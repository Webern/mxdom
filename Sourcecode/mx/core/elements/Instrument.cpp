// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Instrument.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Instrument::Instrument()
        :ElementInterface()
        ,myAttributes( std::make_shared<InstrumentAttributes>() )
        {}


        bool Instrument::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool Instrument::hasContents() const  { return false; }
        std::ostream& Instrument::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& Instrument::streamName( std::ostream& os ) const  { os << "instrument"; return os; }
        std::ostream& Instrument::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        InstrumentAttributesPtr Instrument::getAttributes() const
        {
            return myAttributes;
        }


        void Instrument::setAttributes( const InstrumentAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        bool Instrument::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            return myAttributes->fromXElement( message, xelement );
        }

    }
}
