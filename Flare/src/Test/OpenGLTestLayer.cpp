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
      glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * 8, m_VertexPositions, GL_STATIC_DRAW );

      // Index Buffer
      glGenBuffers( 1, &m_IndexBufferID );
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID );
      glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * 6, m_Indices, GL_STATIC_DRAW );

      // Must enable Vertex Attribute Pointers, before or after they are set does not matter. Where it matters is which buffer is bound. (glBindBuffer)
      //                       Index defined in shader
      glEnableVertexAttribArray( 0 );

      // Vertex Attribute Pointers.
      // Index, size of vertex, Data Type, normalized, stride, offset
      glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( float ) * 2, 0 );

      Platform::OpenGL::ShaderProgramSource x_ProgramSource = Platform::OpenGL::ParseProgram( "testres/Source.shader" );

      m_ShaderProgramID = Platform::OpenGL::CreateShaderProgram( x_ProgramSource.m_VertexSource, x_ProgramSource.m_FragmentSource );

      glUseProgram( m_ShaderProgramID );
   }

   OpenGLTestLayer::~OpenGLTestLayer()
   {
      glDeleteProgram( m_ShaderProgramID );
   }

   void OpenGLTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      //glBindBuffer( GL_ARRAY_BUFFER, m_BufferID );


      //            Mode, Start Index, Vertices Count
      //glDrawArrays( GL_TRIANGLES, 0, 3 );

      //              Mode, Vertices Count, Indices integer type, index buffer id to use (can be nullptr when already bound).
      glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
   }
}