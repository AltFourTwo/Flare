#pragma once

#include "Test/TestObject.h"

#ifdef FLARE_FOR_WINDOWS

extern Flare::Application* Flare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!" );

   Flare::Application* app = Flare::Initialize();
   app->Test();
   app->Run();
   delete app;
}

#endif