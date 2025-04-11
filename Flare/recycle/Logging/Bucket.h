#pragma once

#include "Flare/Core/SmartPointers.h"


namespace Flare::Logging
{
   class Bucket;
   using SharedBucket = Ref<Bucket>;

   class Bucket
   {
      /*****   VARIABLES   *****/
      private:
      bool m_Open = true;

      /*****   C-TOR D-TOR   *****/
      // TODO private ctor and delete copy ctor
      public:
      Bucket( int a );
      virtual ~Bucket() = default;

      /*****   FUNCTIONS   *****/
      public:
      void Open();
      void Close();

      static SharedBucket Create();
   };
}
