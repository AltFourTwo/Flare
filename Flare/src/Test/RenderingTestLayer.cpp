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

      m_VertexBuffer = Rendering::VertexBuffer::Create( m_Vertex, 4 * 6 * sizeof( float ) );
      m_IndexBuffer = Rendering::IndexBuffer::Create( m_Indices, 6 );

      {
         Rendering::BufferLayout x_BufferLayout = {
            { Rendering::ShaderDataType::Float2, "a_Position"},
            { Rendering::ShaderDataType::Float4, "a_Color"}
         };

         m_VertexBuffer->SetLayout( x_BufferLayout );
      }

      m_VertexBuffer->Bind();

      uint32_t x_Index = 0;
      const auto& layout = m_VertexBuffer->GetLayout();
      for ( const auto& x_Element : layout )
      {
         glEnableVertexAttribArray( x_Index );
         glVertexAttribPointer(
            x_Index,
            x_Element.Type.GetComponentCount(),
            Rendering::OpenGLShaderDataTypes::GetUnderlyingTypeOfType( x_Element.Type ),
            x_Element.Normalized ? GL_TRUE : GL_FALSE,
            layout.GetStride(),
            (const void*)x_Element.Offset
         );
         x_Index++;
      }


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
      m_Shader = Rendering::Shader::Create( x_VSrc, x_PSrc );
      m_Shader->Bind();
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
      m_Shader->Bind();
      m_VertexBuffer->Bind();
      m_IndexBuffer->Bind();

      glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );
   }
}