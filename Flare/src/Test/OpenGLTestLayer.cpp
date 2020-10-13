#include "FlarePCH.h"
#include "OpenGLTestLayer.h"

#include "Platforms/OpenGL/Renderer.h"
#include "Platforms/OpenGL/Shader.h"

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

      m_VertexArray = new Flare::OpenGL::VertexArray();

      m_VertexBuffer = new Flare::OpenGL::VertexBuffer(m_VertexPositions, 4 * 2 * sizeof( float ) );
      m_IndexBuffer = new Flare::OpenGL::IndexBuffer(m_Indices, 6);

      m_VertexBufferLayout = new Flare::OpenGL::VertexBufferLayout();

      m_VertexBufferLayout->Push_Float(2);
      m_VertexArray->RegisterBuffer(*m_VertexBuffer, *m_VertexBufferLayout);

      m_Shader = new Flare::OpenGL::Shader( "testres/Source.shader" );
      m_Shader->Bind();
      m_Shader->SetUniform4f( "u_Color", m_R, m_G, m_B, m_A );

      // Could use the Unbind functions, but isn't required. 0 is static.
      GL_DEBUG_WRAPPER( glUseProgram( 0 ) );
      GL_DEBUG_WRAPPER( glBindVertexArray( 0 ) );
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, 0 ) );
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 ) );
   }

   OpenGLTestLayer::~OpenGLTestLayer()
   {
      delete m_VertexBuffer;
      delete m_IndexBuffer;
      delete m_VertexBufferLayout;
      delete m_VertexArray;
      delete m_Shader;
      printf("OpenGLTestLayer Destroyed!\n");
   }

   void OpenGLTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      if ( m_R > 1.0f || m_R < 0.0f )
         m_Increment *= -1;

      m_R += m_Increment;


      // Moved into Renderer.Draw().
      m_Shader->Bind();
      m_Shader->SetUniform4f( "u_Color", m_R, m_G, m_B, m_A );
      //* 
      //* // They get replaced by a Vertex Array Object binding
      //* //GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, m_BufferID ) );
      //* //GL_DEBUG_WRAPPER( glEnableVertexAttribArray( 0 ) );
      //* //GL_DEBUG_WRAPPER( glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), 0 ) );
      //* //GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID ) );
      //* //GL_DEBUG_WRAPPER( glBindVertexArray( m_VertexArrayID ) );
      //* 
      //* m_VertexArray->Bind();
      //* m_IndexBuffer->Bind();
      //* 
      //* //            Mode, Start Index, Vertices Count
      //* //glDrawArrays( GL_TRIANGLES, 0, 3 );
      //* 
      //* //              Mode, Vertices Count, Indices integer type, index buffer id to use (can be nullptr when already bound).
      //* GL_DEBUG_WRAPPER( glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr ) );
      
      m_Renderer.Draw(m_VertexArray, m_IndexBuffer, m_Shader);
   }
}