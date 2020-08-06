#pragma once

#include "Flare/UserInterface/Layer.h"

namespace Flare::ProtoImGui
{
   class FLARE_API ImGuiLayer : public UserInterface::Layer
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      ImGuiLayer();
      ~ImGuiLayer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void OnAttach();
      virtual void OnDetach();
      virtual void OnEvent( Events::Event& a_Event );
      virtual void OnUpdate( Time::TimeStep a_TimeStep );
      virtual void OnRender( Time::TimeStep a_TimeStep );
   };
}