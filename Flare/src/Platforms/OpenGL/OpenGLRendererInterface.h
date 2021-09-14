#pragma once
#include "Flare/Rendering/RendererInterface.h"

namespace Flare::Rendering
{
   class OpenGLRendererInterface : public RendererInterface
   {
      /*****  C-TOR D-TOR  *****/
      public:
      OpenGLRendererInterface();

      /*****   FUNCTIONS   *****/
      public:
      virtual void Init() override;
      virtual void SetViewport( uint32_t a_X, uint32_t a_Y, uint32_t a_Width, uint32_t a_Height ) const override;

      virtual void SetClearColor( const glm::vec4& a_Color ) const override;
      virtual void Clear() const override;

      virtual void DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray ) const override;
   };
}