#pragma once

#include "Core.h"
#include "Logging/ILogEmitter.h"

#include "Time/TimeStep.h"

#include "UserInterface/Window.h"
#include "UserInterface/LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/EventDispatcher.h"

namespace Flare
{
   class FLARE_API Application : private Logging::ILogEmitter
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static Application* s_Instance;
      bool m_Running = true;
      float m_LastFrameTime = 0.0f;
      UserInterface::LayerStack m_LayerStack;
      std::unique_ptr<UserInterface::Window> m_MainWindow;

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
      // Loggers?
   };

   // To be defined in client
   Application* Initialize();
}
