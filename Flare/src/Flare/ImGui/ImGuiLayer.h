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
      virtual void OnAttach() override;
      virtual void OnDetach() override;
      virtual void OnImGuiRender() override;

      void Begin();
      void End();
   };
}