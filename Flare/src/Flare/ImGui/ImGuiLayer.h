#pragma once

#include "Flare/UserInterface/Layer.h"

namespace Flare::ProtoImGui
{
   class ImGuiLayer : public UserInterface::Layer
   {
      /*****  C-TOR D-TOR  *****/
      public:
      ImGuiLayer();
      ~ImGuiLayer();

      /*****   FUNCTIONS   *****/
      public:
      virtual void OnAttach() override;
      virtual void OnDetach() override;
      virtual void OnImGuiRender() override;

      void Begin();
      void End();
   };
}