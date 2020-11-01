#pragma once
#include "Rendering.h"
#include "VertexArray.h"

#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class RendererInterface
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      const API m_API;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      RendererInterface(API a_API);

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static RendererInterface* MakeInterface(API a_API);
      virtual void SetClearColor( const glm::vec4& a_Color ) const = 0;
      virtual void Clear() const = 0;
      virtual void DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray ) const = 0;

      /*****   GETTERS   *****/
      public:
      inline const API GetAPI() const { return m_API; }
   };
}