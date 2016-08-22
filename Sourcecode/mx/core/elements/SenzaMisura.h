// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Strings.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( SenzaMisura )

        inline SenzaMisuraPtr makeSenzaMisura() { return std::make_shared<SenzaMisura>(); }
		inline SenzaMisuraPtr makeSenzaMisura( const XsString& value ) { return std::make_shared<SenzaMisura>( value ); }
		inline SenzaMisuraPtr makeSenzaMisura( XsString&& value ) { return std::make_shared<SenzaMisura>( std::move( value ) ); }

        class SenzaMisura : public ElementInterface
        {
        public:
            SenzaMisura();
            SenzaMisura( const XsString& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            XsString getValue() const;
            void setValue( const XsString& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            XsString myValue;
        };
    }
}
