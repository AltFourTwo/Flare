#include "FlarePCH.h"
#include "RenderingTestLayer.h"

#include "Flare/Rendering/Renderer.h"
#include "Flare/Rendering/Shader.h"

#include <string>
#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

// Temporary
#include "Flare/Rendering/ShaderDataType.h"
#include "Platforms/OpenGL/OpenGLShaderDataTypes.h"

namespace Flare::Testing
{
   RenderingTestLayer::RenderingTestLayer() :
      Layer( "RenderingTestLayer" )
   {
      std::cout << (const char*)glGetString( GL_VERSION ) << std::endl;

      glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
      glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
      glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

      // Rectangle/Square in the back.
      m_VertexArray.reset( Rendering::VertexArray::Create() );

      float x_Vertex[6 * 4] =
      {
         -0.75f, -0.75f, 0.8f, 0.2f, 0.5f, 1.0f,
          0.75f, -0.75f, 0.5f, 0.8f, 0.2f, 1.0f,
          0.75f,  0.75f, 0.2f, 0.5f, 0.8f, 1.0f,
         -0.75f,  0.75f, 0.5f, 0.5f, 0.5f, 1.0f,
      };

      Rendering::BufferLayout x_BufferLayout = {
         { Rendering::ShaderDataType::Float2, "a_Position"},
         { Rendering::ShaderDataType::Float4, "a_Color"}
      };

      std::shared_ptr<Rendering::VertexBuffer> x_VertexBuffer;
      x_VertexBuffer.reset( Rendering::VertexBuffer::Create( x_Vertex, sizeof( x_Vertex ) ) );
      x_VertexBuffer->SetLayout( x_BufferLayout );
      m_VertexArray->AddVertexBuffer( x_VertexBuffer );

      unsigned int x_Indices[6] =
      {
         0, 1, 2,
         2, 3, 0
      };

      std::shared_ptr<Rendering::IndexBuffer> x_IndexBuffer;
      x_IndexBuffer.reset( Rendering::IndexBuffer::Create( x_Indices, sizeof( x_Indices ) / sizeof( uint32_t ) ) );
      m_VertexArray->SetIndexBuffer( x_IndexBuffer );

      // Triangle.
      m_TriangleVertexArray.reset( Rendering::VertexArray::Create() );

      float x_TriangleVertex[6 * 4] =
      {
         -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 1.0f,
          0.5f, -0.5f, 0.2f, 0.0f, 0.8f, 1.0f,
          0.0f,  0.5f, 0.8f, 0.2f, 0.0f, 1.0f,
      };

      Rendering::BufferLayout x_TriangleBufferLayout = {
         { Rendering::ShaderDataType::Float2, "a_Position"},
         { Rendering::ShaderDataType::Float4, "a_Color"}
      };

      std::shared_ptr<Rendering::VertexBuffer> x_TriangleVertexBuffer;
      x_TriangleVertexBuffer.reset( Rendering::VertexBuffer::Create( x_TriangleVertex, sizeof( x_TriangleVertex ) ) );
      x_TriangleVertexBuffer->SetLayout( x_TriangleBufferLayout );
      m_TriangleVertexArray->AddVertexBuffer( x_TriangleVertexBuffer );

      unsigned int x_TriangleIndices[6] =
      {
         0, 1, 2,
      };

      std::shared_ptr<Rendering::IndexBuffer> m_TriangleIndexBuffer;
      m_TriangleIndexBuffer.reset( Rendering::IndexBuffer::Create( x_TriangleIndices, sizeof( x_TriangleIndices ) / sizeof( uint32_t ) ) );
      m_TriangleVertexArray->SetIndexBuffer( m_TriangleIndexBuffer );

      std::string x_VSrc = R"(
         #version 330 core
         
         layout(location = 0) in vec2 a_Position;
         layout(location = 1) in vec4 a_Color;

         out vec2 v_Position;
         out vec4 v_Color;

         void main()
         {
            v_Position = a_Position;
            v_Color = a_Color;
            gl_Position = vec4(a_Position, 1.0 , 1.0);
         }
      )";

      std::string x_PSrc = R"(
         #version 330 core
         
         layout(location = 0) out vec4 x_color;

         in vec2 v_Position;
         in vec4 v_Color;

         void main()
         {
            x_color = v_Color;
         }
      )";

      // TODO : Create shaders with files instead.
      //m_Shader = Rendering::Shader::Create( "testres/Source.shader" );
      m_Shader.reset( Rendering::Shader::Create( x_VSrc, x_PSrc ) );
      m_Shader->Bind();
   }

   RenderingTestLayer::~RenderingTestLayer()
   {
      printf( "RenderingTestLayer Destroyed!\n" );
   }

   void RenderingTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      m_Shader->Bind();
      m_VertexArray->Bind();
      glDrawElements( GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );

      m_TriangleVertexArray->Bind();
      glDrawElements( GL_TRIANGLES, m_TriangleVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );

   }
}