#pragma once

#include "Rendering.h"
#include "RendererCommandInterface.h"
#include "Shader.h"
#include "OrthographicCamera.h"

#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class Renderer
   {
      /*****   NESTED  CLASSES      *****/
      private:
      struct SceneData
      {
         glm::mat4 ViewProjectionMatrix;
      };

      /*****   CLASS   VARIABLES    *****/
      private:
      RendererCommandInterface m_CommandInterface;
      SceneData m_SceneData;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Renderer( API a_API );

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void BeginScene(const OrthographicCamera& a_Camera);
      void EndScene();
      void Submit( const std::shared_ptr<Shader>& a_Shader, const std::shared_ptr<VertexArray>& a_VertexArray );

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