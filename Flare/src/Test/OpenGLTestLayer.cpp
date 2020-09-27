#include "FlarePCH.h"
#include "OpenGLTestLayer.h"
#include "OpenGLUtils.h"

#include <string>
#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::Testing
{
   OpenGLTestLayer::OpenGLTestLayer() :
      Layer( "OpenGLTestLayer" )
   {
      std::cout << (const char*)glGetString( GL_VERSION ) << std::endl;

      glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
      glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
      glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );


      // Vertex Array Object
      GL_DEBUG_WRAPPER( glGenVertexArrays( 1, &m_VertexArrayID ) );
      GL_DEBUG_WRAPPER( glBindVertexArray( m_VertexArrayID ) );

      // Genereate a buffer and bind to it.
      glGenBuffers( 1, &m_BufferID );
      glBindBuffer( GL_ARRAY_BUFFER, m_BufferID );

      // Copy data to the buffer.
      //             Type,            Size in bytes          Data (can be null)   usage
      glBufferData( GL_ARRAY_BUFFER, 4 * 2 * sizeof( float ), m_VertexPositions, GL_STATIC_DRAW );

      // Index Buffer.
      glGenBuffers( 1, &m_IndexBufferID );
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID );
      glBufferData( GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof( unsigned int ), m_Indices, GL_STATIC_DRAW );

      // Must enable Vertex Attribute Pointers, before or after they are set does not matter. Where it matters is which buffer is bound. (glBindBuffer)
      //                       Index defined in shader
      glEnableVertexAttribArray( 0 );

      // Vertex Attribute Pointers.
      // Index, size of vertex, Data Type, normalized, stride, offset
      glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), 0 );

      Platform::OpenGL::ShaderProgramSource x_ProgramSource = Platform::OpenGL::ParseProgram( "testres/Source.shader" );

      m_ShaderProgramID = Platform::OpenGL::CreateShaderProgram( x_ProgramSource.m_VertexSource, x_ProgramSource.m_FragmentSource );

      glUseProgram( m_ShaderProgramID );

      m_u_Color = glGetUniformLocation( m_ShaderProgramID, "u_Color" );
      ASSERT( m_u_Color != -1, "Uniform not found!" );
      glUniform4f( m_u_Color, m_R, m_G, m_B, m_A );

      GL_DEBUG_WRAPPER( glUseProgram( 0 ) );
      GL_DEBUG_WRAPPER( glBindVertexArray( 0 ) );
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, 0 ) );
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 ) );
   }

   OpenGLTestLayer::~OpenGLTestLayer()
   {
      glDeleteProgram( m_ShaderProgramID );
   }

   void OpenGLTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      if ( m_R > 1.0f || m_R < 0.0f )
         m_Increment *= -1;

      m_R += m_Increment;

      GL_DEBUG_WRAPPER( glUseProgram( m_ShaderProgramID ) );
      GL_DEBUG_WRAPPER( glUniform4f( m_u_Color, m_R, m_G, m_B, m_A ) );


      // They get replaced by a Vertex Array Object binding
      //GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, m_BufferID ) );
      //GL_DEBUG_WRAPPER( glEnableVertexAttribArray( 0 ) );
      //GL_DEBUG_WRAPPER( glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), 0 ) );
      //GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID ) );
      GL_DEBUG_WRAPPER( glBindVertexArray( m_VertexArrayID ) );


      //            Mode, Start Index, Vertices Count
      //glDrawArrays( GL_TRIANGLES, 0, 3 );

      //              Mode, Vertices Count, Indices integer type, index buffer id to use (can be nullptr when already bound).
      GL_DEBUG_WRAPPER( glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr ) );
   }
}