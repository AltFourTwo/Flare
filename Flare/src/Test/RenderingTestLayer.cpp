#include "FlarePCH.h"
#include "RenderingTestLayer.h"

#include "Flare/Rendering/Renderer.h"
#include "Flare/Rendering/Shader.h"
//#include "Flare/Rendering/ShaderDataType.h"

#include <string>
#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::Testing
{
   RenderingTestLayer::RenderingTestLayer() :
      Layer( "RenderingTestLayer" )
   {
      std::cout << (const char*)glGetString( GL_VERSION ) << std::endl;

      glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
      glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
      glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

      //m_VertexArray = Rendering::VertexArray::Create();

      m_VertexBuffer = Rendering::VertexBuffer::Create( m_VertexPositions, 4 * 2 * sizeof( float ) );
      m_IndexBuffer = Rendering::IndexBuffer::Create( m_Indices, 6 );

      //m_BufferLayout = Rendering::BufferLayout::Create();
      //m_BufferLayout->Push_Float(2);
      //m_VertexArray->RegisterBuffer(*m_VertexBuffer, *m_BufferLayout);

      Rendering::BufferLayout x_BufferLayout = {
         { Rendering::ShaderDataType::Float3, "a_Position"},
         { Rendering::ShaderDataType::Float4, "a_Color"},
         { Rendering::ShaderDataType::Float2, "a_Normal"}
      };

      m_VertexBuffer->SetLayout(x_BufferLayout);

      std::string x_VSrc = R"(
         #version 330 core
         
         layout(location = 0) in vec3 a_Position;

         out vec3 v_Position;

         void main()
         {
            v_Position = a_Position;
            gl_Position = vec4(a_Position, 1.0);
         }
      )";

      std::string x_PSrc = R"(
         #version 330 core
         
         layout(location = 0) out vec4 x_color;

         in vec3 v_Position;

         void main()
         {
            x_color = vec4( abs(v_Position.yzx)/0.5, 1.0);
         }
      )";

      //m_Shader = Rendering::Shader::Create( "testres/Source.shader" );
      m_Shader = Rendering::Shader::Create( x_VSrc, x_PSrc );
      m_Shader->Bind();
      //m_Shader->SetUniform4f( "u_Color", m_R, m_G, m_B, m_A );

   }

   RenderingTestLayer::~RenderingTestLayer()
   {
      delete m_VertexBuffer;
      delete m_IndexBuffer;
      //delete m_BufferLayout;
      //delete m_VertexArray;
      delete m_Shader;
      printf( "RenderingTestLayer Destroyed!\n" );
   }

   void RenderingTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      //if ( m_R > 1.0f || m_R < 0.0f )
      //   m_Increment *= -1;
      //
      //m_R += m_Increment;


      // Moved into Renderer.Draw().
      m_Shader->Bind();
      //m_Shader->SetUniform4f( "u_Color", m_R, m_G, m_B, m_A );
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

      glEnableVertexAttribArray( 0 );
      glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), 0 );

      m_VertexBuffer->Bind();
      m_IndexBuffer->Bind();

      glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );

      //m_Renderer.Draw(m_VertexArray, m_IndexBuffer, m_Shader);
   }
}