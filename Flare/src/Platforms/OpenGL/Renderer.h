#pragma once

#include "Flare/Core.h"

namespace Flare::OpenGL
{
#define GL_DEBUG_WRAPPER(x) ASSERT( Flare::OpenGL::GLClearErrors(), "OpenGL Error Overflow!\n  In " << __FILE__ << ".\n  At line " << __LINE__ << "." );\
   x;\
   ASSERT(Flare::OpenGL::GLLogCall(#x, __FILE__, __LINE__), "OpenGL Error(s) occured!");

   /*****   NAMESPACE   FUNCTIONS   *****/
   bool GLClearErrors();
   bool GLLogCall( const char* x_Function, const char* x_File, int x_Line );

   class VertexArray;
   class IndexBuffer;
   class Shader;

   class Renderer
   {
      /*****   CLASS   VARIABLES    *****/


      /*****   CLASS   C-TOR D-TOR  *****/

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void Clear() const;
      void Draw( const VertexArray* a_VertexArray, const IndexBuffer* a_IndexBuffer, const Shader* a_Shader ) const; // Shader becomes a 'Material' in more advanced rendering. Shader + Uniforms.
   };
}
