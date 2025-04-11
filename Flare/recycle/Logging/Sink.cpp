#include "FlarePCH.h"
#include "Sink.h"

namespace Flare::Logging
{
   /*****   C-TOR D-TOR   *****/
   Sink::Sink( int a )
   {

   }

   /*****   FUNCTIONS   *****/
   void Sink::Open()
   {

   }

   void Sink::Close()
   {

   }

   SharedSink Sink::Create()
   {
      // Temporary.
      // Weird ambiguous constructor overload if there are no arguments.
      return SharedSink( new Sink( 1 ) );
   }
}
