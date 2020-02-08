#include "Comp.h"

namespace Compose
{

   Comp::Comp()
   {

   }

   Comp::~Comp()
   {

   }

   const char* Format( const char* a_message ... )
   {
      char* l_FormattedMessage = new char[42];
      int i = 0;
      while ( char c = a_message[i++])
      {
         switch ( a_message[i] )
         {
            case Compose::Comp::OPENING_BRACE:

               break;
            case Compose::Comp::CLOSING_BRACE:

               break;
            case Compose::Comp::ALIGNMENT_SEPARATOR:

               break;
            case Compose::Comp::FORMAT_SPERATOR:

               break;
            case Compose::Comp::STRING_LITERAL_DELIMITER:

               break;
            default:

               break;
         }
      }

      return a_message;
   }

   /*
   template<const char* a_message, typename ... Param>
   const char* SomeFormat( const char* a_message, const Param& ... param )
   {



      return a_message;
   }
   */

}
