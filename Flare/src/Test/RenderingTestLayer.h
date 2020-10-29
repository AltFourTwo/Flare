#pragma once

#include "Flare/UserInterface/Layer.h"
#include "Flare/Rendering/Buffer.h"
//#include "Flare/Rendering/VertexBufferLayout.h"
//#include "Flare/Rendering/VertexArray.h"
//#include "Flare/Rendering/IndexBuffer.h"
#include "Flare/Rendering/Shader.h"
#include "Flare/Rendering/Renderer.h"

namespace Flare::Testing
{
   class RenderingTestLayer : public UserInterface::Layer
   {
      public:
      RenderingTestLayer();
      virtual ~RenderingTestLayer();
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;

      //Rendering::VertexArray* m_VertexArray;
      Rendering::VertexBuffer* m_VertexBuffer;
      //Rendering::BufferLayout* m_BufferLayout;
      Rendering::IndexBuffer* m_IndexBuffer;
      Rendering::Shader* m_Shader;

      Rendering::Renderer m_Renderer;

      float m_R = 1.0f;
      float m_G = 0.5f;
      float m_B = 0.0f;
      float m_A = 1.0f;
      float m_Increment = 0.0025f;

      float m_VertexPositions[8] =
      {
         -0.5f, -0.5f,
          0.5f, -0.5f,
          0.5f,  0.5f,
         -0.5f,  0.5f
      };

      unsigned int m_Indices[6] =
      {
         0, 1, 2,
         2, 3, 0
      };
   };
}