#pragma once

namespace Flare::Rendering
{
   class IObject
   {
      /*****   CLASS   VARIABLES    *****/
      private:

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const = 0;
      virtual void Unbind() const = 0;
   };
}