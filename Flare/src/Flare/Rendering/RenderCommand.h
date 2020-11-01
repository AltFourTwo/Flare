#pragma once
#include "RendererInterface.h"

namespace Flare::Rendering
{
   class RenderCommand
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static RendererInterface* s_Interface;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline static const API GetInterfaceAPI() { return s_Interface->GetAPI(); }
      inline static const RendererInterface& CurrentInterface() { return *s_Interface; }

      inline static void SetClearColor( const glm::vec4& a_Color )
      {
         s_Interface->SetClearColor(a_Color);
      }

      inline static void Clear()
      {
         s_Interface->Clear();
      }

      inline static void DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray )
      {
         s_Interface->DrawIndexed( a_VertexArray );
      }
   };
}