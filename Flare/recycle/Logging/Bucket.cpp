#include "FlarePCH.h"
#include "Bucket.h"

namespace Flare::Logging
{
   /*****   C-TOR D-TOR   *****/
   Bucket::Bucket( int a )
   {

   }

   /*****   FUNCTIONS   *****/
   void Bucket::Open()
   {

   }

   void Bucket::Close()
   {

   }

   SharedBucket Bucket::Create()
   {
      // Temporary.
      // Weird ambiguous constructor overload if there are no arguments.
      return SharedBucket( new Bucket( 1 ) );
   }
}
