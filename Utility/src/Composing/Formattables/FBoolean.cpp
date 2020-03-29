#include "UtilityPCH.h"

#include <string>

#include "FBoolean.h"

namespace Composing::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FBoolean::FBoolean( const bool& a_Bool ) :
      m_Bool( a_Bool )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FBoolean::ToString() const
   {
      return m_Bool ? std::string( TEXT_TRUE ) : std::string( TEXT_FALSE );
   }

   std::string FBoolean::ToString( const char*& a_FormatString ) const
   {
      bool x_AsText = false;

      for ( const char* i_ptr = a_FormatString; *i_ptr != 0; i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case 'T':
            case 't':
            {
               if ( *( i_ptr + 1 ) == 'E' || *( i_ptr + 1 ) == 'e' && *( i_ptr + 2 ) == 'X' || *( i_ptr + 2 ) == 'x' && *( i_ptr + 3 ) == 'T' || *( i_ptr + 3 ) == 't' )
                  x_AsText = true;
               else if ( *( i_ptr + 1 ) == '/' && *( i_ptr + 2 ) == 'F' || *( i_ptr + 2 ) == 'f' )
               {
                  if ( x_AsText )
                     return m_Bool ? std::string( TEXT_TRUE ) : std::string( TEXT_FALSE );
                  else
                     return m_Bool ? std::string( 1, CHAR_T ) : std::string( 1, CHAR_F );
               }
               break;
            }

            case 'Y':
            case 'y':
            {
               if ( *( i_ptr + 1 ) == '/' && *( i_ptr + 2 ) == 'N' || *( i_ptr + 2 ) == 'n' )
               {
                  if ( x_AsText )
                     return m_Bool ? std::string( TEXT_YES ) : std::string( TEXT_NO );
                  else
                     return m_Bool ? std::string( 1, CHAR_Y ) : std::string( 1, CHAR_N);
               }
               break;
            }

            case 'O':
            case 'o':
            {
               if ( *( i_ptr + 1 ) == '/' && *( i_ptr + 2 ) == 'X' || *( i_ptr + 2 ) == 'x' )
                  return m_Bool ? std::string( 1, CHAR_O ) : std::string( 1, CHAR_X );
               break;
            }

            default:
               break;
         }
      }
      return std::to_string( m_Bool );
   }
}