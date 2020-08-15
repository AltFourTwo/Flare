#include "SandboxPCH.h"

#include <Flare.h>
#include "Flare/UserInterface/Layer.h"
#include "Flare/UserInput/Input.h"
#include "Flare/UserInput/InputCodes.h"

class ExampleLayer : public Flare::UserInterface::Layer
{
   public:
   ExampleLayer() :
      Layer( "Test Layer" )
   {}

   virtual void Layer::OnUpdate( Flare::Time::TimeStep a_TimeStep )
   {
      //if ( Flare::UserInput::Input::IsKeyPressed( FLARE_KEY_G ) )
      //   Flare::Application::GetInstance().
   }

   virtual void Layer::OnRender( Flare::Time::TimeStep a_TimeStep )
   {

   }

   virtual void Layer::OnEvent( Flare::Events::Event& a_Event )
   {

   }

   virtual void Layer::OnAttach()
   {

   }

   virtual void Layer::OnDetach()
   {

   }
};

class Sandbox : public Flare::Application
{
public:
   Sandbox()
   {
      PushLayer(new ExampleLayer());
      PushOverlay(new Flare::ProtoImGui::ImGuiLayer());
   }

   ~Sandbox()
   {

   }

};


Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}