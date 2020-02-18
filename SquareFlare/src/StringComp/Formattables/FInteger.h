#pragma once

#include <string>

#include "SquareFlare/Core.h"
#include "StringComp/IFormattable.h"

namespace Compose::Formattables
{
   class FInteger : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      int& m_Int;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FInteger( int& a_Int );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}