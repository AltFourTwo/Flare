#pragma once

#include "Flare/Core.h"
#include "Flare/Logging/Console.h"
#include "Flare/Resource/ResourceManager.h"
#include "Flare/Rendering/RenderingController.h"

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

namespace Flare
{
   class Application
   {
      /*****   VARIABLES   *****/
      private:
      // Singletons
      static Application* s_Instance;
      Logging::Console m_Console;
      ResourceManager m_ResourceManager;
      Rendering::RenderingController m_RenderingController;

      // Windows and Layers
      std::unique_ptr<UserInterface::Window> m_MainWindow;
      UserInterface::LayerStack m_LayerStack;
      ProtoImGui::ImGuiLayer* m_ImGuiLayer;

      // Runtime variables.
      bool m_Running = true;
      bool m_Minimized = false;
      bool m_MainWindowFocused = true;
      bool m_NoPauseOutsideFocus = false;
      float m_LastFrameTime = 0.0f;

      /*****  C-TOR D-TOR  *****/
      public:
      Application();
      virtual ~Application();

      /*****   FUNCTIONS   *****/
      public:
      void Run();
      void PopLayer( UserInterface::Layer* a_Layer );
      void PushLayer( UserInterface::Layer* a_Layer );
      void PopOverlay( UserInterface::Layer* a_Overlay );
      void PushOverlay( UserInterface::Layer* a_Overlay );

      /*****   EVENT   HANDLERS     *****/
      private:
      void OnEvent( Events::Event& e );
      bool OnWindowFocus( Events::WindowFocusEvent& e );
      bool OnWindowLostFocus( Events::WindowLostFocusEvent& e );
      bool OnWindowResize( Events::WindowResizeEvent& e );
      bool OnWindowClose( Events::WindowCloseEvent& e );

      /*****   GETTERS   *****/
      public:
      inline static Application& GetInstance() { return *s_Instance; }
      inline static const Rendering::RenderingController& GetRenderingController() { return s_Instance->m_RenderingController; }
      inline static UserInterface::Window& GetWindow() { return *s_Instance->m_MainWindow; }

      /*****   SETTERS   *****/
   };

   // To be defined in client
   Application* Initialize();
}
