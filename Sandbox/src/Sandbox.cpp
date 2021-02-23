#include "SandboxPCH.h"
#include "Sandbox.h"

#include <Flare.h>
#include "ExampleLayer.h"

Sandbox::Sandbox()
{
   // ( *this->GetConsole().GetClientLogger() ).SetParameters( Flare::Logging::LoggerParameters( "Sandbox", Flare::Logging::LogLevel::Trace, "%F at %T | &N says : &M" ) );

   PushLayer( new ExampleLayer() );
   FLARE_TRACE( "Sandbox has pushed 1 layer!\n" );
}

Sandbox::~Sandbox() {}

Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}