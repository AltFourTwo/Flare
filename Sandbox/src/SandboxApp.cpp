#include "SandboxPCH.h"

#include <Flare.h>

class Sandbox : public Flare::Application
{
public:
   Sandbox()
   {
      //PushLayer(new ExampleLayer())
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