#pragma once

#include "Flare/Core.h"

namespace Flare::OpenGL
{
#define GL_DEBUG_WRAPPER(x) ASSERT( Flare::OpenGL::GLClearErrors(), "OpenGL Error Overflow!\n  In " << __FILE__ << ".\n  At line " << __LINE__ << "." );\
   x;\
   ASSERT(Flare::OpenGL::GLLogCall(#x, __FILE__, __LINE__), "OpenGL Error(s) occured!");

   bool GLClearErrors();
   bool GLLogCall( const char* x_Function, const char* x_File, int x_Line );
}