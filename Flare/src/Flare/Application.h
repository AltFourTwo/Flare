#pragma once

#include "Flare/Core.h"
#include "Flare/Logging/Console.h"
#include "Flare/Logging/LogEmitter.h"

#include "Flare/Time/TimeStep.h"

#include "Flare/UserInterface/Window.h"
#include "Flare/UserInterface/LayerStack.h"
#include "Flare/ImGui/ImGuiLayer.h"

#include "Flare/Events/Event.h"
#include "Flare/Events/ApplicationEvent.h"
#include "Flare/Events/WindowEvent.h"
#include "Flare/Events/KeyEvent.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/EventDispatcher.h"

// Testing Only
#include "Test/OpenGLTestLayer.h"

namespace Flare
{
   class FLARE_API Application : private Logging::CoreLogEmitter
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static Application* s_Instance;
      bool m_Running = true;
      float m_LastFrameTime = 0.0f;
      UserInterface::LayerStack m_LayerStack;
      std::unique_ptr<UserInterface::Window> m_MainWindow;
      ProtoImGui::ImGuiLayer* m_ImGuiLayer;

      // For OpenGL testing
      Testing::OpenGLTestLayer* m_OpenGLLayer;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Application();
      virtual ~Application();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline UserInterface::Window& GetWindow() { return *m_MainWindow; }
      inline static Application& GetInstance() { return *s_Instance; }
      void Run();
      void PopLayer( UserInterface::Layer* a_Layer );
      void PushLayer( UserInterface::Layer* a_Layer );
      void PopOverlay( UserInterface::Layer* a_Overlay );
      void PushOverlay( UserInterface::Layer* a_Overlay );

      /*****   EVENT   HANDLERS     *****/
      private:
      void OnEvent( Events::Event& e );
      bool OnWindowClose( Events::WindowCloseEvent& e );

      /*****   GETTERS   *****/

      /*****   SETTERS   *****/
   };

   // To be defined in client
   Application* Initialize();
}
