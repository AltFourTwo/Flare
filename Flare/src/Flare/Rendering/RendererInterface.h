#pragma once
#include "Rendering.h"

#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class VertexArray;

   class RendererInterface
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      const API m_API;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      RendererInterface(API a_API);

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Ref<RendererInterface> CreateInterface(API a_API);
      virtual void SetClearColor( const glm::vec4& a_Color ) const = 0;
      virtual void Clear() const = 0;
      virtual void DrawIndexed( const Ref<VertexArray>& a_VertexArray ) const = 0;

      /*****   GETTERS   *****/
      public:
      inline const API GetAPI() const { return m_API; }
   };
}