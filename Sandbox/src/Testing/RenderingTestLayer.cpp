#include "SandboxPCH.h"
#include "RenderingTestLayer.h"

#include <glm/gtc/type_ptr.hpp> // Temporary ?
#include <imgui.h>

namespace SandboxTesting
{
   /*****  C-TOR D-TOR  *****/
   RenderingTestLayer::RenderingTestLayer() :
      Layer( "RenderingTestLayer" ),
      m_OrthographicCameraController( 1280.0f, 720.0f, true )
   {
      // Rectangle/Square in the back.
      m_VertexArray = Flare::Rendering::VertexArray::Create();

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
      x_VertexBuffer = Flare::Rendering::VertexBuffer::Create( x_Vertex, sizeof( x_Vertex ) );
      x_VertexBuffer->SetLayout( x_BufferLayout );
      m_VertexArray->AddVertexBuffer( x_VertexBuffer );

      unsigned int x_Indices[6] =
      {
         0, 1, 2,
         2, 3, 0
      };

      std::shared_ptr<Flare::Rendering::IndexBuffer> x_IndexBuffer;
      x_IndexBuffer = Flare::Rendering::IndexBuffer::Create( x_Indices, sizeof( x_Indices ) / sizeof( uint32_t ) );
      m_VertexArray->SetIndexBuffer( x_IndexBuffer );

      // Triangle.
      m_TriangleVertexArray = Flare::Rendering::VertexArray::Create();

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
      x_TriangleVertexBuffer = Flare::Rendering::VertexBuffer::Create( x_TriangleVertex, sizeof( x_TriangleVertex ) );
      x_TriangleVertexBuffer->SetLayout( x_TriangleBufferLayout );
      m_TriangleVertexArray->AddVertexBuffer( x_TriangleVertexBuffer );

      unsigned int x_TriangleIndices[6] =
      {
         0, 1, 2,
      };

      std::shared_ptr<Flare::Rendering::IndexBuffer> m_TriangleIndexBuffer;
      m_TriangleIndexBuffer = Flare::Rendering::IndexBuffer::Create( x_TriangleIndices, sizeof( x_TriangleIndices ) / sizeof( uint32_t ) );
      m_TriangleVertexArray->SetIndexBuffer( m_TriangleIndexBuffer );

      //Flare::Ref<Flare::FileAsset> x_VertexSource = Flare::ResourceManager::GetInstance().LoadAsset<Flare::FileAsset>
      //   ( "./resources/shaders/Color.vertex.glsl" , "Vertex Shader", true );
      //
      //Flare::Ref<Flare::FileAsset> x_PixelSource = Flare::ResourceManager::GetInstance().LoadAsset<Flare::FileAsset>
      //   ( "./resources/shaders/Color.pixel.glsl", "Pixel Shader", true );

      //m_Shader = Flare::Rendering::Shader::Create( x_VertexSource->AsText(), x_PixelSource->AsText() );

      Flare::Ref<Flare::FileAsset> x_SomeSource = Flare::ResourceManager::GetInstance().LoadAsset<Flare::FileAsset>
         ( "./resources/shaders/ShaderTest.notglsl", "Test Shader", true );

      m_Shader = Flare::Rendering::Shader::Create( x_SomeSource->AsText() );

      m_Shader->Bind();
   }

   RenderingTestLayer::~RenderingTestLayer()
   {
      printf( "RenderingTestLayer Destroyed!" );
   }

   /*****   FUNCTIONS   *****/
   void RenderingTestLayer::OnUpdate( Flare::Time::TimeStep a_TimeStep )
   {
      m_OrthographicCameraController.OnUpdate( a_TimeStep );
   }

   void RenderingTestLayer::OnRender( Flare::Time::TimeStep a_TimeStep )
   {
      Flare::Rendering::Renderer& x_Renderer = Flare::Rendering::RenderingController::GetRenderer();

      x_Renderer.BeginScene( m_OrthographicCameraController.GetCamera() );

      x_Renderer.Submit( m_Shader, m_VertexArray );
      x_Renderer.Submit( m_Shader, m_TriangleVertexArray );

      x_Renderer.EndScene();
   }

   void RenderingTestLayer::OnImGuiRender()
   {
      //ImGui::Begin( "Controls" );
      //ImGui::DragFloat3( "Position", glm::value_ptr( m_CameraPosition ), 0.1f, -1.0f, 1.0f );
      //ImGui::DragFloat( "Rotation", &m_CameraRotation, 0.5f, -360.0f, 360.0f );
      //ImGui::End();
   }

   /*****   EVENT HANDLERS   *****/
   void RenderingTestLayer::OnEvent( Flare::Events::Event& a_Event )
   {
      m_OrthographicCameraController.OnEvent( a_Event );
   }

   bool RenderingTestLayer::OnKeyPressedEvent( Flare::Events::KeyPressedEvent& a_Event )
   {
      return false;
   }
}