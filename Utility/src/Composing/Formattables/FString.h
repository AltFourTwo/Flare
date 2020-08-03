#pragma once

#include "IFormattable.h"

namespace Utility::Composing::Formattables
{
   class FString : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const std::string& m_String;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FString( const std::string& a_String );
      FString( const char* a_CString );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}