#pragma once

//#include "Test/TestObject.h"

#ifdef FLARE_FOR_WINDOWS

extern Flare::Application* Flare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!\n" );

   Flare::Application* app = Flare::Initialize();
   app->Run();
   app->Shutdown();

   printf( "Its over!\n" );
}

#endif