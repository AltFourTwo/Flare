#pragma once

#include "Flare/UserInterface/Layer.h"
#include "Platforms/OpenGL/VertexBuffer.h"
#include "Platforms/OpenGL/VertexBufferLayout.h"
#include "Platforms/OpenGL/VertexArray.h"
#include "Platforms/OpenGL/IndexBuffer.h"
#include "Platforms/OpenGL/Shader.h"

namespace Flare::Testing
{
   class OpenGLTestLayer : public UserInterface::Layer
   {
      public:
      OpenGLTestLayer();
      virtual ~OpenGLTestLayer();
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;

      Flare::OpenGL::VertexArray* m_VertexArray;
      Flare::OpenGL::VertexBuffer* m_VertexBuffer;
      Flare::OpenGL::VertexBufferLayout* m_VertexBufferLayout;
      Flare::OpenGL::IndexBuffer* m_IndexBuffer;
      Flare::OpenGL::Shader* m_Shader;

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