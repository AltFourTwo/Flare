#pragma once

#include "Flare/UserInterface/Layer.h"


namespace Flare::Testing
{
   class OpenGLTestLayer : public UserInterface::Layer
   {
      public:
      OpenGLTestLayer();
      virtual void OnRender( Time::TimeStep a_TimeStep ) override;
   };
}