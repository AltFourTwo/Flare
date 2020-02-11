#include "Formatter.h"

namespace Compose
{

   // Why are you calling the default constructor?!?!?
   Formatter::Formatter( const Utils::StringExtract& a_FormatString )
   {
      StringFormatSection x_Section = INDEX;
      bool x_Aligned;
      bool x_Formatted;
      bool x_ReadingStringLitteral = false;
      const char* x_IndexStart;
      const char* x_AlignStart;
      const char* x_FormatStart;

      const char* i = a_FormatString.ViewExtract();
      while ( *i++ != 0 )
      {
         switch ( *i )
         {
            case Compose::ALIGNMENT_SEPARATOR:
               x_Aligned = true;
               x_Section = ALIGNMENT;
               break;
            case Compose::FORMAT_SPERATOR:
               x_Formatted = true;
               x_Section = FORMAT;
               break;
            case Compose::STRING_LITERAL_DELIMITER:
               if ( x_Section != FORMAT )
                  throw;
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
