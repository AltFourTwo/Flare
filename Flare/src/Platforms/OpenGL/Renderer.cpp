#include "FlarePCH.h"
#include "Renderer.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{
   /*****   NAMESPACE   FUNCTIONS   *****/
   bool GLClearErrors()
   {
      int x_ErrorCount = 0;

      while ( glGetError() != GL_NO_ERROR )
      {
         x_ErrorCount++;

         if ( x_ErrorCount >= 10 )
            return false;
      }

      return true;
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

   /*****   CLASS   FUNCTIONS    *****/
   void Renderer::Clear() const
   {
      glClearColor( 0.5f, 0.25f, 0, 1 );
      glClear( GL_COLOR_BUFFER_BIT );
   }

   void Renderer::Draw( const VertexArray* a_VertexArray, const IndexBuffer* a_IndexBuffer, const Shader* a_Shader ) const
   {
      a_Shader->Bind();
      // Uniforms must be set before draw.
      //a_Shader.SetUniform4f( "u_Color", m_R, m_G, m_B, m_A );

      // They get replaced by a Vertex Array Object binding
      //GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, m_BufferID ) );
      //GL_DEBUG_WRAPPER( glEnableVertexAttribArray( 0 ) );
      //GL_DEBUG_WRAPPER( glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), 0 ) );
      //GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID ) );
      //GL_DEBUG_WRAPPER( glBindVertexArray( m_VertexArrayID ) );

      a_VertexArray->Bind();
      a_IndexBuffer->Bind();

      GL_DEBUG_WRAPPER( glDrawElements( GL_TRIANGLES, a_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr ) );
   }
}