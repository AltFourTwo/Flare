#pragma once

#include "Flare/Core/SmartPointers.h"

namespace Flare::Logging
{
   class Sink;
   using SharedSink = Ref<Sink>;

   class Sink
   {
      /*****   VARIABLES   *****/
      private:
      bool m_Open = true;

      /*****   C-TOR D-TOR   *****/
      // TODO private ctor and delete copy ctor
      public:
      Sink( int a );
      virtual ~Sink() = default;

      /*****   FUNCTIONS   *****/
      public:
      void Open();
      void Close();

      static SharedSink Create();
   };
}
