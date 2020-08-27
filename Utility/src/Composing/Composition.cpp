#include "UtilityPCH.h"

#include <string>
#include <vector>
#include <initializer_list>

#include "Composition.h"
#include "Formatter.h"
#include "ErrorCodes.h"
#include "Exceptions/UtilityException.h"

namespace Utility::Composing
{
   std::string Format( const char* a_Message, std::initializer_list<Formattable> a_FormattableObjects )
   {
      std::vector<Utility::Strings::StringExtract> x_Extracts;
      ExtractFormatStrings( a_Message, x_Extracts );

      if ( x_Extracts.size() == 0 )
         return a_Message;

      std::string x_Message;
      std::vector<std::string> x_FormattedElements;
      x_FormattedElements.reserve( a_FormattableObjects.size() );
      bool x_ReplacingFormatEnclosure = false;
      size_t x_ExtractsSize = 0;
      size_t x_StringSize = 0;

      const Formattable* x_ObjectsPtr = a_FormattableObjects.begin();

      for ( Utility::Strings::StringExtract x_Extract : x_Extracts )
      {
         const Formatter x_Formatter( x_Extract );

         if ( x_Formatter.Index() > a_FormattableObjects.size() )
            throw Utility::Exceptions::UtilityException(ErrorCodes::Composing::INDEX_OUT_OF_RANGE, "Index does not point to any of the passed parameter(s).");

         std::string& x_FormattedObject = x_Formatter.FormatObject( *( x_ObjectsPtr + x_Formatter.Index() ) );

         x_ExtractsSize += x_Extract.Length();
         x_StringSize += x_FormattedObject.length();

         x_FormattedElements.push_back( x_FormattedObject );
      }

      x_Message.reserve( strlen( a_Message ) - x_ExtractsSize + x_StringSize );

      std::vector<Utility::Strings::StringExtract>::iterator itr_Extracts = x_Extracts.begin();
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

   void ExtractFormatStrings( const char* a_Text, std::vector<Utility::Strings::StringExtract>& a_Extracts )
   {
      bool x_ReadingFormatEnclosure = false;
      bool x_Ignore = false;
      const char* x_FormatStringStart = 0;

      const char* i_ptr = a_Text;
      while ( *i_ptr != 0 )
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

         i_ptr++;
      }

      if ( x_ReadingFormatEnclosure )
         throw; // TODO Exception format string not closed.
   }
}
