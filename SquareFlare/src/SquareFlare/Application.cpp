#include "Application.h"
#include "Utils/TestObject.h"

namespace SquareFlare
{

   Application::Application()
   {}


   Application::~Application()
   {}


   void Application::Run()
   {
      while ( true );
   }
   

   void Application::Test()
   {
      TestObject hello;

      TestObject bonjour;
      bonjour.x = 5;
      bonjour.y = 10;
   }

   
}
