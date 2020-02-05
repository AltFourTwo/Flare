#pragma once

#ifdef F2D_FOR_WINDOWS

extern Flare2D::Application* Flare2D::Initialize();

int main(int argc, char** argv)
{
   //printf( "It begins!" );
   Flare2D::Application* app = Flare2D::Initialize();
   app->Run();
   delete app;
}

#endif