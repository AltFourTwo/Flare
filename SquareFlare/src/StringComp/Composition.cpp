#include "Composition.h"
#include "Formatter.h"

namespace Compose
{

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string Format( const char* a_Message, std::initializer_list<Formattable> a_FormattableObjects )
   {
      std::vector<Utils::StringExtract> x_Extracts;
      ExtractFormatStrings( a_Message, x_Extracts );

      if ( x_Extracts.size() == 0 )
         return a_Message;

      std::string x_Message;
      std::vector<std::string> x_FormattedElements;
      x_FormattedElements.reserve( a_FormattableObjects.size() );
      bool x_ReplacingFormatEnclosure = false;
      int x_ExtractsSize = 0;
      int x_StringSize = 0;

      const Formattable* x_ObjectsPtr = a_FormattableObjects.begin();

      for ( Utils::StringExtract x_Extract : x_Extracts )
      {
         const Formatter x_Formatter( x_Extract );

         if ( x_Formatter.Index() > a_FormattableObjects.size() )
            throw; // TODO Exception Index does not point to any of the passed parameter(s).

         std::string& x_FormattedObject = x_Formatter.FormatObject( *( x_ObjectsPtr + x_Formatter.Index() ) );

         x_ExtractsSize += x_Extract.Length();
         x_StringSize += x_FormattedObject.length();

         x_FormattedElements.push_back( x_FormattedObject );
      }

      x_Message.reserve( strlen( a_Message ) - x_ExtractsSize + x_StringSize );

      std::vector<Utils::StringExtract>::iterator itr_Extracts = x_Extracts.begin();
      std::vector<std::string>::iterator itr_FormattedElements = x_FormattedElements.begin();
      const char* i_ptr = a_Message;
      while ( *i_ptr != 0 )
      {
         switch ( *i_ptr )
         {
            case OPENING_BRACE:
               if ( i_ptr == itr_Extracts->ExtractStart() )
               {
                  x_ReplacingFormatEnclosure = true;
                  x_Message.append( *itr_FormattedElements );
                  itr_FormattedElements++;
               }
               break;

            case CLOSING_BRACE:
               if ( i_ptr == itr_Extracts->ExtractEnd() )
               {
                  x_ReplacingFormatEnclosure = false;
                  itr_Extracts++;
               }
               break;

            default:
               if ( !x_ReplacingFormatEnclosure )
                  x_Message += *i_ptr;
               break;
         }
         i_ptr++;
      }

      return x_Message;
   }

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void ExtractFormatStrings( const char* a_Text, std::vector<Utils::StringExtract>& a_Extracts )
   {
      bool x_ReadingFormatEnclosure = false;
      bool x_Ignore = false;
      const char* x_FormatStringStart = 0;

      const char* i_ptr = a_Text;
      while ( *i_ptr++ != 0 )
      {
         switch ( *i_ptr )
         {
            case OPENING_BRACE:
               if ( !x_ReadingFormatEnclosure )
               {
                  x_ReadingFormatEnclosure = true;
                  x_FormatStringStart = i_ptr;
               }
               break;

            case CLOSING_BRACE:
               if ( x_ReadingFormatEnclosure && !x_Ignore )
               {
                  x_ReadingFormatEnclosure = false;
                  a_Extracts.emplace_back( x_FormatStringStart, i_ptr );
               }
               break;

            case STRING_LITERAL_DELIMITER:
               if ( x_ReadingFormatEnclosure )
                  x_Ignore = !x_Ignore;
               break;
         }
      }

      if ( x_ReadingFormatEnclosure )
         throw; // TODO Exception format string not closed.
   }
}
