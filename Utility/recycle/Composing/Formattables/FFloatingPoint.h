#pragma once

#include "IFormattable.h"

namespace Utility::Composing::Formattables
{
   class FFloatingPoint : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const double& m_FloatingPoint;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FFloatingPoint( const double& a_FloatingPoint );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}

