#include "Comp.h"
#include "Formatter.h"

namespace Compose
{

   Composition::Composition()
   {

   }

   Composition::~Composition()
   {

   }

   std::string Format( const char* a_Message ... )
   {
      std::vector<Utils::StringExtract> x_Extracts = Compose::ExtractFormatStrings(a_Message);

      for ( auto iterator = x_Extracts.begin(); iterator < x_Extracts.end(); iterator++ )
      {
         
      }

      return a_Message;
   }

   std::vector<Utils::StringExtract> ExtractFormatStrings( const char* a_Text )
   {
      std::vector<Utils::StringExtract> x_Extracts;
      bool x_ReadingFormatEnclosure = false;
      bool x_Ignore = false;
      const char* x_FormatStringStart = 0;

      const char* i_ptr = a_Text;
      while ( *i_ptr++ != 0 )
      {
         switch ( *i_ptr )
         {
            case Composition::OPENING_BRACE:
               if ( !x_ReadingFormatEnclosure )
               {
                  x_ReadingFormatEnclosure = true;
                  x_FormatStringStart = i_ptr;
               }
               break;

            case Composition::CLOSING_BRACE:
               if ( x_ReadingFormatEnclosure && !x_Ignore )
               {
                  x_ReadingFormatEnclosure = false;
                  x_Extracts.push_back( Utils::StringExtract( x_FormatStringStart, i_ptr ) );
               }
               break;

            case Composition::STRING_LITERAL_DELIMITER:
               if ( x_ReadingFormatEnclosure ) 
                  x_Ignore = !x_Ignore;
               break;
         }
      }
      if ( x_ReadingFormatEnclosure )
         throw; // TODO Exception format string not closed.

      return x_Extracts;
   }



   /*
   template<const char* a_message, typename ... Param>
   const char* SomeFormat( const char* a_message, const Param& ... param )
   {



      return a_message;
   }
   */
}
