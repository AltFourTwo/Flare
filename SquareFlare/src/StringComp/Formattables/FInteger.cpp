
#include "SquareFlare/Core.h"
#include "FInteger.h"
#include "StringComp/Formattable.h"
#include "Utils/NumberUtils.h"

namespace Compose::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FInteger::FInteger( int& a_Int ) :
      m_Int( a_Int )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FInteger::ToString() const
   {
      return std::to_string( m_Int );
   }

   std::string FInteger::ToString( const char*& a_FormatString ) const
   {
      int x_Base = 10;
      int x_Padding = 0;

      for ( const char* i_ptr = a_FormatString; *i_ptr != 0; i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case 'B':
            case 'b':
            {
               x_Base = Utils::Numbers::ConvertTwoCharsToInt( *( i_ptr + 1 ), *( i_ptr + 2 ) );
               break;
            }

            case 'X':
            case 'x':
            {
               x_Base = 16;
               x_Padding = 8;
               break;
            }

            case 'P':
            case 'p':
            {
               x_Padding = Utils::Numbers::ConvertTwoCharsToInt( *( i_ptr + 1 ), *( i_ptr + 2 ) );
               break;
            }

            default:
               break;
         }
      }

      if ( x_Base < 2 )
         x_Base = 2;

      std::string x_Out( Utils::Numbers::ConvertToBase( x_Base, m_Int ));

      if ( x_Padding > 0 )
      {
         std::string x_Padded;
         x_Padded.reserve( x_Padding );
         int x_CharDiff = x_Padding - x_Out.length();

         if ( x_CharDiff > 0 )
         {
            x_Padded.append( x_CharDiff, '0' );
            x_Padded.append( x_Out );
         }
         else
            x_Padded.append( x_Out, abs( x_CharDiff ), x_Padding );

         x_Out.swap( x_Padded );
      }

      if ( x_Base == 16 )
      {
         std::string x_Hex;
         x_Hex.reserve( 2 + x_Out.length() );
         x_Hex += "0x";
         x_Hex += x_Out;
         return x_Hex;
      }

      return x_Out;
   }
}