#pragma once
#include <Flare.h>

#include <memory>

namespace SandboxTesting
{
   class RenderingTestLayer : public Flare::UserInterface::Layer
   {
      /*****   VARIABLES   *****/
      Flare::Rendering::OrthographicCameraController m_OrthographicCameraController;
      Flare::Ref<Flare::Rendering::Shader> m_Shader;
      Flare::Ref<Flare::Rendering::VertexArray> m_VertexArray;
      Flare::Ref<Flare::Rendering::VertexArray> m_TriangleVertexArray;

      /*****  C-TOR D-TOR  *****/
      public:
      RenderingTestLayer();
      virtual ~RenderingTestLayer();

      /*****   FUNCTIONS   *****/
      virtual void OnUpdate( Flare::Time::TimeStep a_TimeStep ) override;
      virtual void OnRender( Flare::Time::TimeStep a_TimeStep ) override;
      virtual void OnImGuiRender() override;

      /*****   EVENT HANDLERS   *****/
      virtual void OnEvent( Flare::Events::Event& a_Event ) override;
      bool OnKeyPressedEvent( Flare::Events::KeyPressedEvent& a_Event );
   };
}