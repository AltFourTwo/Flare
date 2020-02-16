#pragma once

#include "Utils/TestObject.h"
#include <iostream>

#ifdef SQFL_FOR_WINDOWS

extern SquareFlare::Application* SquareFlare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!" );

   std::cout << "\nAAAAA\n";
   //std::cout << Compose::Format( "Maybe", { 2, 4, 4, 6 } ) << "\n";
   //std::cout << Compose::Format( "No" ) << "\n";

   SquareFlare::Application* app = SquareFlare::Initialize();
   app->Test();
   app->Run();
   delete app;
}

#endif