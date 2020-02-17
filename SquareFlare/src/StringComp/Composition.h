#pragma once

#include <string>
#include <vector>

#include "SquareFlare/Core.h"
#include "Utils/StringExtract.h"
#include "Formattable.h"

namespace Compose
{
   class SQFL_API Composition
   {
      /***************************\
      \*****   ENUMERATORS   *****/
      public:
      enum ControlCharacters
      {
         OPENING_BRACE = '{',
         CLOSING_BRACE = '}',
         ALIGNMENT_SEPARATOR = ',',
         FORMAT_SPERATOR = ':',
         STRING_LITERAL_DELIMITER = '\''
      };

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Composition();
      ~Composition();

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:

   };

   SQFL_API std::string Format( const char* a_Message, std::initializer_list<Formattable> a_FormattableObjects );
   SQFL_API void ExtractFormatStrings( std::vector<Utils::StringExtract>& a_Extracts, const char* a_Text );
}