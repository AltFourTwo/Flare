#pragma once

#include <string>
#include <cstdarg>
#include <vector>

#include "../SquareFlare/Core.h"
#include "Utils/StringExtract.h"

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

   SQFL_API std::string Format( const char* a_Message ... );
   SQFL_API std::vector<Utils::StringExtract> ExtractFormatStrings( const char* a_Text );
   //SQFL_API const char* Extract( const char* a_Message, const char* a_ExtractStart, const char* a_ExtractEnd );
}



