#pragma once

#include "Core.h"
#include "Logging/Console.h"

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
   class FLARE_API Application
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      bool m_Running = true;
      static Logging::Console& s_Console;
      static Logging::Logger::SharedLogger s_CoreLogger;
      static Logging::Logger::SharedLogger s_ClientLogger;
      float m_LastFrameTime = 0.0f;
      UserInterface::LayerStack m_LayerStack;
      std::unique_ptr<UserInterface::Window> m_MainWindow;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Application();
      virtual ~Application();

      /*****   CLASS   FUNCTIONS    *****/
      public:
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
