#pragma once

#include "Flare/Core.h"
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
      virtual void OnEvent( Flare::Events::Event& e ) = 0;
      virtual void OnUpdate() = 0;
      virtual void OnRender() = 0;
   };
}