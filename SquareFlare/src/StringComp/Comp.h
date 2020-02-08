#pragma once

#include <cstdarg>
#include "../SquareFlare/Core.h"

 namespace Compose
{

   class SQFL_API Comp
   {
      
      /*
      static const char OPENING_BRACE              = '{';
      static const char CLOSING_BRACE              = '}';
      static const char ALIGNMENT_SEPARATOR        = ',';
      static const char FORMAT_SPERATOR            = ':';
      static const char STRING_LITERAL_DELIMITER   = '\'';
      */

   public:
      enum ControlCharacters
      {
         OPENING_BRACE = '{',
         CLOSING_BRACE = '}',
         ALIGNMENT_SEPARATOR = ',',
         FORMAT_SPERATOR = ':',
         STRING_LITERAL_DELIMITER = '\''
      };

      Comp();
      ~Comp();

   };

   SQFL_API const char* Format( const char* a_message ... );
}

