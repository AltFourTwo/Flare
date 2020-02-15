#include "Composition.h"
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
      std::vector<Utils::StringExtract> x_Extracts;
      ExtractFormatStrings( x_Extracts, a_Message );

      if ( x_Extracts.size() == 0 )
         return a_Message;

      for ( Utils::StringExtract x_Extract : x_Extracts )
      {
         Formatter x_Formatter = Formatter( x_Extract );

         // x_Formatter.m_Index
         // Validate Indexes?
      }

      return a_Message;
   }

   void ExtractFormatStrings( std::vector<Utils::StringExtract>& a_Extracts, const char* a_Text )
   {
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
                  a_Extracts.emplace_back( x_FormatStringStart, i_ptr );
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
   }



   /*
   template<const char* a_message, typename ... Param>
   const char* SomeFormat( const char* a_message, const Param& ... param )
   {



      return a_message;
   }
   */
}
