#pragma once
#include <Flare.h>

#include <memory>

namespace SandboxTesting
{
   class RenderingTestLayer : public Flare::UserInterface::Layer
   {
      /*****   VARIABLES   *****/
      Flare::Rendering::OrthographicCamera m_OrthographicCamera;
      Flare::Ref<Flare::Rendering::Shader> m_Shader;
      Flare::Ref<Flare::Rendering::VertexArray> m_VertexArray;
      Flare::Ref<Flare::Rendering::VertexArray> m_TriangleVertexArray;

      glm::vec3 m_CameraPosition = glm::vec3( 0.0f, 0.0f, 0.0f );
      float m_CameraRotation = 0.0f;

      /*****  C-TOR D-TOR  *****/
      public:
      RenderingTestLayer();
      virtual ~RenderingTestLayer();

      /*****   FUNCTIONS   *****/
      virtual void OnEvent( Flare::Events::Event& a_Event ) override;
      virtual void OnUpdate( Flare::Time::TimeStep a_TimeStep ) override;
      virtual void OnRender( Flare::Time::TimeStep a_TimeStep ) override;
      virtual void OnImGuiRender() override;

      bool OnKeyPressedEvent( Flare::Events::KeyPressedEvent& a_Event );
   };
}