#pragma once

#include <string>
#include <cstdarg>
#include <vector>

#include "../SquareFlare/Core.h"
#include "Formatter.h"

namespace Compose
{
   /***************************\
   \*****   ENUMERATORS   *****/
   enum ControlCharacters
   {
      OPENING_BRACE = '{',
      CLOSING_BRACE = '}',
      ALIGNMENT_SEPARATOR = ',',
      FORMAT_SPERATOR = ':',
      STRING_LITERAL_DELIMITER = '\''
   };

   enum StringFormatSection
   {
      INDEX = 1,
      ALIGNMENT = 2,
      FORMAT = 3
   };

   class SQFL_API Comp
   {
      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Comp();
      ~Comp();

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:

   };

   SQFL_API std::string Format( const char* a_Message ... );
   SQFL_API std::vector<Utils::StringExtract> ExtractFormatStrings( const char* a_Text );
   //SQFL_API const char* Extract( const char* a_Message, const char* a_ExtractStart, const char* a_ExtractEnd );
}



