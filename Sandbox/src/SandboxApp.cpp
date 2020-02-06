#include <SquareFlare.h>

class Sandbox : public SquareFlare::Application
{
public:
   Sandbox()
   {

   }

   ~Sandbox()
   {

   }

};


SquareFlare::Application* SquareFlare::Initialize()
{
   return new Sandbox();
}