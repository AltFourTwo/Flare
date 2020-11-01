#pragma once

#include "RenderCommand.h"

namespace Flare::Rendering
{
   class Renderer
   {
      /*****   CLASS   FUNCTIONS    *****/
      public:
      static void BeginScene();
      static void EndScene();
      static void Submit( const std::shared_ptr<VertexArray>& a_VertexArray );

      /*****   GETTERS   *****/
      public:
      inline static const API GetCommandInterfaceAPI() { return RenderCommand::GetInterfaceAPI(); }
   };
}