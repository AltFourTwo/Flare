#pragma once

#include "Flare/UserInterface/Layer.h"
#include "Flare/Rendering/VertexArray.h"
#include "Flare/Rendering/Shader.h"
#include "Flare/Rendering/OrthographicCamera.h"

#include <memory>

namespace Flare::Testing
{
   class RenderingTestLayer : public UserInterface::Layer
   {
      /*****   CLASS   VARIABLES    *****/
      Rendering::OrthographicCamera m_OrthographicCamera;
      std::shared_ptr<Rendering::Shader> m_Shader;
      std::shared_ptr<Rendering::VertexArray> m_VertexArray;
      std::shared_ptr<Rendering::VertexArray> m_TriangleVertexArray;

      glm::vec3 m_CameraPosition = glm::vec3( 0.0f, 0.0f, 0.0f );
      float m_CameraRotation = 0.0f;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      RenderingTestLayer();
      virtual ~RenderingTestLayer();

      /*****   CLASS   FRIENDS      *****/
      virtual void OnUpdate( Time::TimeStep a_TimeStep ) override;
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;
      virtual void OnImGuiRender() override;
   };
}