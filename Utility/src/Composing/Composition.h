#pragma once

#include "Strings/StringExtract.h"
#include "Formattable.h"

namespace Composing
{
   enum ControlCharacters
   {
      OPENING_BRACE = '{',
      CLOSING_BRACE = '}',
      ALIGNMENT_SEPARATOR = ',',
      FORMAT_SPERATOR = ':',
      STRING_LITERAL_DELIMITER = '\''
   };

   std::string Format( const char* a_Message, std::initializer_list<Formattable> a_FormattableObjects );
   void ExtractFormatStrings( const char* a_Text, std::vector<Utility::Strings::StringExtract>& a_Extracts );
}