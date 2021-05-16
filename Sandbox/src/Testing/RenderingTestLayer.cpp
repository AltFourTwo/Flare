#include "SandboxPCH.h"
#include "RenderingTestLayer.h"

#include "Flare/UserInput/Input.h"
#include "Flare/Events/EventDispatcher.h"
#include "Flare/Rendering/RenderingController.h"

#include <glm/gtc/type_ptr.hpp> // Temporary ?
#include <imgui.h>

namespace SandboxTesting
{
   RenderingTestLayer::RenderingTestLayer() :
      Layer( "RenderingTestLayer" ),
      m_OrthographicCamera( -1.0f, 1.0f, -1.0f, 1.0f )
   {
      // Rectangle/Square in the back.
      m_VertexArray.reset( Flare::Rendering::VertexArray::Create() );

      float x_Vertex[7 * 4] =
      {
         -0.75f, -0.75f, 0.0f, 0.8f, 0.2f, 0.5f, 1.0f,
          0.75f, -0.75f, 0.0f, 0.5f, 0.8f, 0.2f, 1.0f,
          0.75f,  0.75f, 0.0f, 0.2f, 0.5f, 0.8f, 1.0f,
         -0.75f,  0.75f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f,
      };

      Flare::Rendering::BufferLayout x_BufferLayout = {
         { Flare::Rendering::ShaderDataType::DataType::Float3, "a_Position"},
         { Flare::Rendering::ShaderDataType::DataType::Float4, "a_Color"}
      };

      std::shared_ptr<Flare::Rendering::VertexBuffer> x_VertexBuffer;
      x_VertexBuffer.reset( Flare::Rendering::VertexBuffer::Create( x_Vertex, sizeof( x_Vertex ) ) );
      x_VertexBuffer->SetLayout( x_BufferLayout );
      m_VertexArray->AddVertexBuffer( x_VertexBuffer );

      unsigned int x_Indices[6] =
      {
         0, 1, 2,
         2, 3, 0
      };

      std::shared_ptr<Flare::Rendering::IndexBuffer> x_IndexBuffer;
      x_IndexBuffer.reset( Flare::Rendering::IndexBuffer::Create( x_Indices, sizeof( x_Indices ) / sizeof( uint32_t ) ) );
      m_VertexArray->SetIndexBuffer( x_IndexBuffer );

      // Triangle.
      m_TriangleVertexArray.reset( Flare::Rendering::VertexArray::Create() );

      float x_TriangleVertex[7 * 3] =
      {
         -0.5f, -0.5f, 0.0f, 0.0f, 0.8f, 0.2f, 1.0f,
          0.5f, -0.5f, 0.0f, 0.2f, 0.0f, 0.8f, 1.0f,
          0.0f,  0.5f, 0.0f, 0.8f, 0.2f, 0.0f, 1.0f,
      };

      Flare::Rendering::BufferLayout x_TriangleBufferLayout = {
         { Flare::Rendering::ShaderDataType::DataType::Float3, "a_Position"},
         { Flare::Rendering::ShaderDataType::DataType::Float4, "a_Color"}
      };

      std::shared_ptr<Flare::Rendering::VertexBuffer> x_TriangleVertexBuffer;
      x_TriangleVertexBuffer.reset( Flare::Rendering::VertexBuffer::Create( x_TriangleVertex, sizeof( x_TriangleVertex ) ) );
      x_TriangleVertexBuffer->SetLayout( x_TriangleBufferLayout );
      m_TriangleVertexArray->AddVertexBuffer( x_TriangleVertexBuffer );

      unsigned int x_TriangleIndices[6] =
      {
         0, 1, 2,
      };

      std::shared_ptr<Flare::Rendering::IndexBuffer> m_TriangleIndexBuffer;
      m_TriangleIndexBuffer.reset( Flare::Rendering::IndexBuffer::Create( x_TriangleIndices, sizeof( x_TriangleIndices ) / sizeof( uint32_t ) ) );
      m_TriangleVertexArray->SetIndexBuffer( m_TriangleIndexBuffer );

      std::string x_VSrc = R"(
         #version 330 core
         
         layout(location = 0) in vec3 a_Position;
         layout(location = 1) in vec4 a_Color;

         uniform mat4 u_ViewProjection;

         out vec3 v_Position;
         out vec4 v_Color;

         void main()
         {
            v_Position = a_Position;
            v_Color = a_Color;
            gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
         }
      )";

      std::string x_PSrc = R"(
         #version 330 core
         
         layout(location = 0) out vec4 x_color;

         in vec3 v_Position;
         in vec4 v_Color;

         void main()
         {
            x_color = v_Color;
         }
      )";

      // TODO : Create shaders with files instead.
      //m_Shader = Rendering::Shader::Create( "testres/Source.shader" );
      m_Shader.reset( Flare::Rendering::Shader::Create( x_VSrc, x_PSrc ) );
      m_Shader->Bind();
   }

   RenderingTestLayer::~RenderingTestLayer()
   {
      printf( "RenderingTestLayer Destroyed!\n" );
   }

   void RenderingTestLayer::OnEvent( Flare::Events::Event& a_Event )
   {
      Flare::Events::EventDispatcher x_Dispatcher( a_Event );
      x_Dispatcher.Dispatch<Flare::Events::KeyPressedEvent>( FLARE_BIND_EVENT_FN( RenderingTestLayer::OnKeyPressedEvent ) );
   }

   bool RenderingTestLayer::OnKeyPressedEvent( Flare::Events::KeyPressedEvent& a_Event )
   {
      return false;
   }

   void RenderingTestLayer::OnUpdate( Flare::Time::TimeStep a_TimeStep )
   {
      Flare::UserInput::Input& x_Input = Flare::UserInput::Input::GetInstance();

      if ( x_Input.IsKeyPressed( FLARE_KEY_LEFT ) )
         m_CameraPosition.x -= a_TimeStep.GetSeconds() ;

      if ( x_Input.IsKeyPressed( FLARE_KEY_RIGHT ) )
         m_CameraPosition.x += a_TimeStep.GetSeconds();

      if ( x_Input.IsKeyPressed( FLARE_KEY_UP ) )
         m_CameraPosition.y += a_TimeStep.GetSeconds();

      if ( x_Input.IsKeyPressed( FLARE_KEY_DOWN ) )
         m_CameraPosition.y -= a_TimeStep.GetSeconds();

      m_OrthographicCamera.SetPosition( m_CameraPosition );
      m_OrthographicCamera.SetRotation( m_CameraRotation );
   }

   void RenderingTestLayer::OnRender( Flare::Time::TimeStep a_TimeStep )
   {
      Flare::Rendering::Renderer& x_Renderer = Flare::Rendering::RenderingController::GetRenderer();

      x_Renderer.BeginScene( m_OrthographicCamera );

      x_Renderer.Submit( m_Shader, m_VertexArray );
      x_Renderer.Submit( m_Shader, m_TriangleVertexArray );

      x_Renderer.EndScene();
   }

   void RenderingTestLayer::OnImGuiRender()
   {
      ImGui::Begin( "Controls" );

      ImGui::DragFloat3( "Position", glm::value_ptr( m_CameraPosition ), 0.1f, -1.0f, 1.0f );
      ImGui::DragFloat( "Rotation", &m_CameraRotation, 0.5f, -360.0f, 360.0f );

      ImGui::End();
   }
}