#pragma once
#include "Rendering.h"
#include "RendererCommandInterface.h"

#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class Shader;
   class OrthographicCamera;

   class Renderer
   {
      /*****   NESTED      *****/
      private:
      struct SceneData
      {
         glm::mat4 ViewProjectionMatrix;
      };

      /*****   VARIABLES   *****/
      private:
      RendererCommandInterface m_CommandInterface;
      SceneData m_SceneData;

      /*****  C-TOR D-TOR  *****/
      public:
      Renderer( API a_API );

      /*****   FUNCTIONS   *****/
      public:
      void Init();
      void BeginScene(const OrthographicCamera& a_Camera);
      void EndScene();
      void Submit( const Ref<Shader>& a_Shader, const Ref<VertexArray>& a_VertexArray );

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