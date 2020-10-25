#pragma once

#ifdef FLARE_FOR_WINDOWS

extern Flare::Application* Flare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!\n" );

   Flare::Application* app = Flare::Initialize();
   FLARE_CORE_TRACE( "App Initialized!\n" );

   app->Run();
   delete app;
}

#endif