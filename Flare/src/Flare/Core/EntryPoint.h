#pragma once
#include "Flare/Core/Core.h"
#include "Flare/Core/Assert.h"
#include "Flare/Core/Log.h"
#include "Flare/Core/Application.h"

#ifdef FLARE_FOR_WINDOWS

extern Flare::Application* Flare::Start();

int main( int argc, char** argv )
{
   printf( "It begins!\n" );

   Flare::Application* app = Flare::Start();
   FLARE_CORE_TRACE( "App Initialized!" );

   app->Run();
   delete app;
}

#endif