#include "UtilityPCH.h"

#include "FString.h"

namespace Composing::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FString::FString( const std::string& a_String ) :
      m_String( a_String )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FString::ToString() const
   {
      return m_String;
   }

   std::string FString::ToString( const char*& a_FormatString ) const
   {
      // TODO Finish implementing this.
      for ( const char* i_ptr = a_FormatString; *i_ptr != 0; i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case 'A':
            {
               if ( *( i_ptr + 1 ) == 'B' && *( i_ptr + 2 ) == 'C' )
                  break;
               break;
            }

            case 'a':
            {
               if ( *( i_ptr + 1 ) == 'b' && *( i_ptr + 2 ) == 'c' )
                  break;
               break;
            }

            default:
               break;
         }
      }
      return "String Formatted";
   }
}