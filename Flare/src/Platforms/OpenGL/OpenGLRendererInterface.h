#pragma once
#include "Flare/Rendering/RendererInterface.h"

namespace Flare::Rendering
{
   class OpenGLRendererInterface : public RendererInterface
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLRendererInterface();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void SetClearColor( const glm::vec4& a_Color ) const override;
      virtual void Clear() const override;
      virtual void DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray ) const override;
   };
}