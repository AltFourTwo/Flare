#pragma once

#include "Flare/UserInterface/Layer.h"

namespace Flare::Testing
{
   class OpenGLTestLayer : public UserInterface::Layer
   {
      public:
      OpenGLTestLayer();
      virtual ~OpenGLTestLayer();
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;

      unsigned int m_BufferID;
      unsigned int m_IndexBufferID;
      unsigned int m_ShaderProgramID;

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