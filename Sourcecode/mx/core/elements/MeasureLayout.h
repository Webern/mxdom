// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ELEMENT( MeasureDistance )
        MX_FORWARD_DECLARE_ELEMENT( MeasureLayout )

        inline MeasureLayoutPtr makeMeasureLayout() { return std::make_shared<MeasureLayout>(); }

        class MeasureLayout : public ElementInterface
        {
        public:
            MeasureLayout();

            virtual bool hasAttributes() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual bool hasContents() const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;

            /* _________ MeasureDistance minOccurs = 0, maxOccurs = 1 _________ */
            MeasureDistancePtr getMeasureDistance() const;
            void setMeasureDistance( const MeasureDistancePtr& value );
            bool getHasMeasureDistance() const;
            void setHasMeasureDistance( const bool value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            MeasureDistancePtr myMeasureDistance;
            bool myHasMeasureDistance;
        };
    }
}
