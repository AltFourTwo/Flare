#include "FlarePCH.h"
#include "Renderer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{

   void GLClearErrors()
   {
      while ( glGetError() != GL_NO_ERROR );
   }

   bool GLLogCall( const char* x_Function, const char* x_File, int x_Line )
   {
      bool x_NoErrorFound = true;
      while ( GLenum x_Error = glGetError() )
      {
         std::cout << "OpenGL Error [" << x_Error << "]\n";
         x_NoErrorFound = false;
      }

      if ( !x_NoErrorFound )
         std::cout << "In " << x_File << " at line " << x_Line << ".\n";

      return x_NoErrorFound;
   }
}