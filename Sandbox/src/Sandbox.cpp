#include "SandboxPCH.h"
#include "Sandbox.h"

#include <Flare.h>
#include "ExampleLayer.h"

Sandbox::Sandbox() :
   LogEmitter( Flare::Logging::LoggerParameters( "Sandbox", Flare::Logging::LogLevel::TRACE, "%F at %T | &N says : &M" ) )
{
   PushLayer( new ExampleLayer() );
   FLARE_TRACE( "Sandbox has pushed 1 layers!" );
}

Sandbox::~Sandbox() {}

Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}