#pragma once

#include "Flare/UserInterface/Layer.h"
#include "Flare/Events/ApplicationEvent.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/KeyEvent.h"
#include "Flare/Events/WindowEvent.h"
#include "Flare/Events/ClipBoardEvent.h"

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

      private:
      bool OnMouseButtonPressed( Flare::Events::MouseButtonPressedEvent& a_Event );
      bool OnMouseButtonReleased( Flare::Events::MouseButtonReleasedEvent& a_Event );
      bool OnMouseMoved( Flare::Events::MouseMovedEvent& a_Event );
      bool OnMouseScrolled( Flare::Events::MouseScrolledEvent& a_Event );
      bool OnKeyPressed( Flare::Events::KeyPressedEvent& a_Event );
      bool OnKeyReleased( Flare::Events::KeyReleasedEvent& a_Event );
      bool OnKeyTyped( Flare::Events::KeyTypedEvent& a_Event );
      bool OnWindowResized( Flare::Events::WindowResizeEvent& a_Event );
      bool OnClipBoardCut( Flare::Events::ClipBoardCutEvent& a_Event );
      bool OnClipBoardCopy( Flare::Events::ClipBoardCopyEvent& a_Event );
      bool OnClipBoardPaste( Flare::Events::ClipBoardPasteEvent& a_Event );
   };
}