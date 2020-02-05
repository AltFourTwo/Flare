#include <Flare2D.h>

class Sandbox : public Flare2D::Application
{
public:
   Sandbox()
   {

   }

   ~Sandbox()
   {

   }

};


Flare2D::Application* Flare2D::Initialize()
{
   return new Sandbox();
}