#include "FlarePCH.h"
#include "OpenGLTestLayer.h"
#include "OpenGLUtils.h"

#include "Flare/Application.h"
#include "Flare/Logging/LogEmitter.h"

#include <string>
#include <iostream>

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Flare::Testing
{
   OpenGLTestLayer::OpenGLTestLayer() :
      Layer( "OpenGLTestLayer" )
   {
      std::cout << (const char*)glGetString( GL_VERSION ) << std::endl;

      // Genereate a buffer and bind to it.
      glGenBuffers( 1, &m_BufferID );
      glBindBuffer( GL_ARRAY_BUFFER, m_BufferID );

      // Copy data to the buffer.
      //             Type,            Size in bytes       Data (can be null)   usage
      glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * 6, m_VertexPositions, GL_STATIC_DRAW );

      // Must enable Vertex Attribute Pointers, before or after they are set does not matter. Where it matters is which buffer is bound. (glBindBuffer)
      //                       Index defined in shader
      glEnableVertexAttribArray( 0 );

      // Vertex Attribute Pointers.
      // Index, size of vertex, Data Type, normalized, stride, offset
      glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( float ) * 2, 0 );

      // Shaders!
      std::string x_VertexShaderSource =
         "#version 460 core\n"
         "\n"
         "layout(location = 0) in vec4 x_Position;\n"
         "\n"
         "void main()\n"
         "{\n"
         "   gl_Position = x_Position;\n"
         "}\n";

      std::string x_FragmentShaderSource =
         "#version 460 core\n"
         "\n"
         "layout(location = 0) out vec4 x_Color;\n"
         "\n"
         "void main()\n"
         "{\n"
         "   x_Color = vec4(1.0, 0.0, 0.0, 1.0);\n"
         "}\n";

      m_ShaderProgramID = Platform::OpenGL::CreateShaderProgram( x_VertexShaderSource, x_FragmentShaderSource );

      glUseProgram( m_ShaderProgramID );
   }

   OpenGLTestLayer::~OpenGLTestLayer()
   {
      glDeleteProgram( m_ShaderProgramID );
   }

   void OpenGLTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      //glBindBuffer( GL_ARRAY_BUFFER, m_BufferID );

      glDrawArrays( GL_TRIANGLES, 0, 3 );
      //glDrawElements(GL_TRIANGLES, 3, ,)
   }
}