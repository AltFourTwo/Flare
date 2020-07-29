#pragma once

#include "Flare/Core.h"
#include "Flare/Time/TimeStep.h"
#include "Flare/Events/Event.h"

namespace Flare::UserInterface
{
   class FLARE_API Layer
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      std::string m_DebugName;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Layer(const std::string& a_Name = "Layer");
      virtual ~Layer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void OnAttach() = 0;
      virtual void OnDetach() = 0;
      virtual void OnEvent( Flare::Events::Event& a_Event ) = 0;
      virtual void OnUpdate( Time::TimeStep a_TimeStep ) = 0;
      virtual void OnRender() = 0;
   };
}