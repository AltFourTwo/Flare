#pragma once

#include "Utils/TestObject.h"
#include "StringComp/IFormattable.h"
#include <iostream>

#ifdef SQFL_FOR_WINDOWS

extern SquareFlare::Application* SquareFlare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!" );

   std::cout << "\nAAAAA\n";

   int y = 2;
   int z = 4;
   int az = 4;
   int pbg = 6;

   std::cout << Compose::Format( "Maybe", { y, z, az, pbg } ) << "\n";
   //std::cout << Compose::Format( "No" ) << "\n";

   SquareFlare::Application* app = SquareFlare::Initialize();
   app->Test();
   app->Run();
   delete app;
}

#endif