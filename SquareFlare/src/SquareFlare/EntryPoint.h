#pragma once

#ifdef SQFL_FOR_WINDOWS

extern SquareFlare::Application* SquareFlare::Initialize();

int main( int argc, char** argv )
{
   printf( "It begins!" );
   printf( Compose::Format( "Maybe", 2, 4, 4, 6 ) );
   printf( Compose::Format( "No" ) );
   SquareFlare::Application* app = SquareFlare::Initialize();
   app->Run();
   delete app;
}

#endif