#include "SandboxPCH.h"

#include <Flare.h>

class Sandbox : public Flare::Application
{
public:
   Sandbox()
   {

   }

   ~Sandbox()
   {

   }

};


Flare::Application* Flare::Initialize()
{
   return new Sandbox();
}