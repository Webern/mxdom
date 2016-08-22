// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/Extend.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        Extend::Extend()
        :ElementInterface()
        ,myAttributes( std::make_shared<ExtendAttributes>() )
        {}


        bool Extend::hasAttributes() const
        {
            return myAttributes->hasValues();
        }


        bool Extend::hasContents() const  { return false; }
        std::ostream& Extend::streamAttributes( std::ostream& os ) const
        {
            if ( myAttributes )
            {
                myAttributes->toStream( os );
            }
            return os;
        }


        std::ostream& Extend::streamName( std::ostream& os ) const  { os << "extend"; return os; }
        std::ostream& Extend::streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const
        {
            MX_UNUSED( indentLevel );
            isOneLineOnly = true;
            return os;
        }


        ExtendAttributesPtr Extend::getAttributes() const
        {
            return myAttributes;
        }


        void Extend::setAttributes( const ExtendAttributesPtr& value )
        {
            if ( value )
            {
                myAttributes = value;
            }
        }


        bool Extend::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            return myAttributes->fromXElement( message, xelement );
        }

    }
}
