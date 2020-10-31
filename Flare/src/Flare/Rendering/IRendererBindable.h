#pragma once

namespace Flare::Rendering
{
   class IRendererBindable
   {
      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const = 0;
      virtual void Unbind() const = 0;
   };
}