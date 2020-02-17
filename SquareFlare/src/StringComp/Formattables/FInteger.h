#pragma once

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
      virtual const char* ToString() const;
      virtual const char* ToString( const char*& a_FormatString ) const;
   };
}