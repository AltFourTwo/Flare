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

      TestObject hi;
      hi.x = 5;
      hi.y = 10;

      Compose::Format( "This is a message from : {0}.", hi );

      Compose::Format( "This is a message from : {0,-1}.", hi );

      Compose::Format( "This is a message from : {0:'{'format'}'}.", hi );

      Compose::Format( "This is a message from : {0:'{'format'}',-15}.", hi );

      Compose::Format( "This is a message from : {0,15:'{'format'}'}.", hi );
   }
}
