#pragma once

#include "Flare/Core.h"

namespace Flare::OpenGL
{
#define GL_DEBUG_WRAPPER(x) Flare::OpenGL::GLClearErrors();\
   x;\
   ASSERT(Flare::OpenGL::GLLogCall(#x, __FILE__, __LINE__), "OpenGL Error(s) occured!");

   void GLClearErrors();
   bool GLLogCall( const char* x_Function, const char* x_File, int x_Line );
}