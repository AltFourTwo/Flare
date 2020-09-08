#include "SandboxPCH.h"

#include <Flare.h>
#include "Sandbox.h"

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

Sandbox::Sandbox() :
   LogEmitter( Flare::Logging::LoggerParameters( "Sandbox", Flare::Logging::LogLevel::TRACE, "%F at %T | &N says : &M" ) )
{
   PushLayer( new ExampleLayer() );
   PushOverlay( new Flare::ProtoImGui::ImGuiLayer() );
   FLARE_TRACE( "Sandbox has pushed 2 layers!" );
}

Sandbox::~Sandbox() {}

Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}