#include "Formatter.h"

namespace Compose
{
   Formatter::Formatter( const Utils::StringExtract& a_FormatString )
   {
      StringFormatSection x_Section = INDEX;
      bool x_Aligned = false;
      bool x_Formatted = false;
      bool x_ReadingStringLitteral = false;
      const char* x_IndexStart;
      const char* x_AlignStart;
      const char* x_FormatStart;

      for ( const char* i_ptr = a_FormatString.ExtractStart(); i_ptr <= a_FormatString.ExtractEnd(); i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case Compose::OPENING_BRACE:
               if ( i_ptr == a_FormatString.ExtractStart() )
                  x_IndexStart = a_FormatString.ExtractStart() + 1;
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected { in format string.
               break;

            case Compose::CLOSING_BRACE:
               if ( i_ptr == a_FormatString.ExtractEnd() )
                  throw; // not really
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected } in format string.
               break;

            case Compose::ALIGNMENT_SEPARATOR:
               if ( x_Aligned && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unescaped second , in format string.
               x_Aligned = true;
               x_Section = ALIGNMENT;
               break;

            case Compose::FORMAT_SPERATOR:
               if ( x_Formatted && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unescaped second : in format string.
               x_Formatted = true;
               x_Section = FORMAT;
               break;

            case Compose::STRING_LITERAL_DELIMITER:
               if ( x_Section != FORMAT )
                  throw; // TODO Exception string litteral found outside format.
               x_ReadingStringLitteral = x_ReadingStringLitteral ? false : true;
               break;

            default:
               break;
         }
      }
   }


   Formatter::~Formatter()
   {}
}
