#pragma once

#include "Rendering.h"
#include "RendererCommandInterface.h"

namespace Flare::Rendering
{
   class Renderer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      RendererCommandInterface m_CommandInterface;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Renderer( API a_API );

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void BeginScene();
      void EndScene();
      void Submit( const std::shared_ptr<VertexArray>& a_VertexArray );

      /*****   GETTERS   *****/
      public:
      inline const RendererCommandInterface& GetCommandInterface() const
      {
         return m_CommandInterface;
      }

      inline const API GetCommandInterfaceAPI() const
      {
         return m_CommandInterface.GetInterfaceAPI();
      }
   };
}