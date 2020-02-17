#include <iostream>

#include "Application.h"
#include "Utils/TestObject.h"
#include "StringComp/Composition.h"

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

      int y = 2;
      int z = 4;
      int az = 4;
      int pbg = 6;

      std::cout << Compose::Format( "This is a message from : {0}.", { hi } ).c_str() << "\n";

      std::cout << Compose::Format( "This is a message from : {0,-1}.", { hi } ).c_str() << "\n";

      std::cout << Compose::Format( "This is a message from : {0:'{'format'}'}.", { hi } ).c_str() << "\n";

      std::cout << Compose::Format( "This is a message from : {0:'{'format'}',-15}.", { hi } ).c_str() << "\n";

      std::cout << Compose::Format( "This is a message from : {0,15:'{'format'}'}.", { hi } ).c_str() << "\n";

      std::cout << Compose::Format( "This is a message from : {0,15:'{'format'}'} and {1,15:X}.", { hi, hi }  ).c_str() << "\n";

      std::cout << Compose::Format( "Maybe {0},{1},{2},{3}.", { y, z, az, pbg } ).c_str() << "\n";
   }
}
