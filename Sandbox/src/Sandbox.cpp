#include "SandboxPCH.h"
#include "Sandbox.h"

#include <Flare.h>
#include "ExampleLayer.h"
#include "Testing/RenderingTestLayer.h"

#include <windows.h>
#include <iostream>

Sandbox::Sandbox()
{
   PushLayer( new ExampleLayer() );
   PushLayer( new SandboxTesting::RenderingTestLayer() );
   FLARE_TRACE( "Sandbox has pushed 2 layers!" );

   // Global
   // system( "Color 0A" );
   // FLARE_TRACE( "Green Text !" );

   HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleTextAttribute( hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
   FLARE_TRACE( "Intense Green Text ?" );
   SetConsoleTextAttribute( hstdout, FOREGROUND_GREEN );
   FLARE_TRACE( "Green Text ?" );
   SetConsoleTextAttribute( hstdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
   FLARE_TRACE( "Intense Blue Text ?" );
   SetConsoleTextAttribute( hstdout, FOREGROUND_BLUE );
   FLARE_TRACE( "Blue Text ?" );
   SetConsoleTextAttribute( hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY );
   FLARE_TRACE( "Intense Red Text ?" );
   SetConsoleTextAttribute( hstdout, FOREGROUND_RED );
   FLARE_TRACE( "Red Text ?" );

   /* Doesn't work
   std::string _String = '\033' + "[91;100m";
   std::cout << _String ;
   FLARE_TRACE("Green Text ?");
   */
}

Sandbox::~Sandbox() {}
