#include "Comp.h"

namespace Compose
{

   Comp::Comp()
   {

   }

   Comp::~Comp()
   {

   }

   std::string Format( const char* a_Message ... )
   {
      std::vector<Formatter> x_Formatters;
      bool x_ReadingFormatEnclosure = false;
      bool x_Ignore = false;
      const char* x_FormatStringStart = 0;

      int i = 0;
      while ( char c = a_Message[i++] )
      {
         switch ( c )
         {
            case Compose::OPENING_BRACE:
               if ( x_ReadingFormatEnclosure && !x_Ignore )
                  // Throws invalid format string : unexpected {
                  throw;

               if ( a_Message[i + 1] == OPENING_BRACE )
                  i++;
               else
               {
                  x_ReadingFormatEnclosure = true;
                  x_FormatStringStart = ( a_Message + i );
               }

               break;

            case Compose::CLOSING_BRACE:
               if ( x_ReadingFormatEnclosure && !x_Ignore )
               {
                  x_ReadingFormatEnclosure = false;
                  x_Formatters.push_back( Formatter( Utils::StringExtract(x_FormatStringStart, ( a_Message + i ) - x_FormatStringStart ) ) );
               }
               else if ( !x_ReadingFormatEnclosure && a_Message[i + 1] == CLOSING_BRACE )
                  i++;
               else
               {
                  // Throws invalid format string : unexpected }
                  throw;
               }
               break;

            case Compose::STRING_LITERAL_DELIMITER:
               x_Ignore = x_Ignore ? false : true;
               break;

            default:
               break;
         }
      }

      return a_Message;
   }
   
      /*
      template<const char* a_message, typename ... Param>
      const char* SomeFormat( const char* a_message, const Param& ... param )
      {



         return a_message;
      }
      */

}
