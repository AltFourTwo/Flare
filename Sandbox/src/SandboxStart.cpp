#include "SandboxPCH.h"
#include "Sandbox.h"

#include "Flare/Core/EntryPoint.h"

Flare::Application* Flare::Start()
{
   return new Sandbox();
}