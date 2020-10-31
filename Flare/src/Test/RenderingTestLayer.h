#pragma once

#include "Flare/UserInterface/Layer.h"
#include "Flare/Rendering/Buffer.h"
#include "Flare/Rendering/VertexArray.h"
#include "Flare/Rendering/Shader.h"
#include "Flare/Rendering/Renderer.h"

#include <memory>

namespace Flare::Testing
{
   class RenderingTestLayer : public UserInterface::Layer
   {
      public:
      RenderingTestLayer();
      virtual ~RenderingTestLayer();
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;

      std::shared_ptr<Rendering::Shader> m_Shader;
      std::shared_ptr<Rendering::VertexArray> m_VertexArray;
      std::shared_ptr<Rendering::VertexArray> m_TriangleVertexArray;
   };
}