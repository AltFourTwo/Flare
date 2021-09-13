#pragma once
#include "Flare/Core.h"
#include "Flare/Application.h"

#ifdef FLARE_FOR_WINDOWS

extern Flare::Application* Flare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!\n" );

   Flare::Application* app = Flare::Initialize();
   FLARE_CORE_TRACE( "App Initialized!" );

   app->Run();
   delete app;
}

#endif