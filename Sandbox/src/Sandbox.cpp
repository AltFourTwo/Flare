#include "SandboxPCH.h"
#include "Sandbox.h"

#include <Flare.h>
#include "ExampleLayer.h"
#include "Testing/RenderingTestLayer.h"

Sandbox::Sandbox()
{
   // ( *this->GetConsole().GetClientLogger() ).SetParameters( Flare::Logging::LoggerParameters( "Sandbox", Flare::Logging::LogLevel::Trace, "%F at %T | &N says : &M" ) );

   PushLayer( new ExampleLayer() );
   PushLayer( new SandboxTesting::RenderingTestLayer() );
   FLARE_TRACE( "Sandbox has pushed 2 layers!" );
}

Sandbox::~Sandbox() {}

Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}