#pragma once

#include <iostream>

#include "Utils/TestObject.h"
#include "StringComp/IFormattable.h"

#ifdef SQFL_FOR_WINDOWS

extern SquareFlare::Application* SquareFlare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!" );

   SquareFlare::Application* app = SquareFlare::Initialize();
   app->Test();
   app->Run();
   delete app;
}

#endif