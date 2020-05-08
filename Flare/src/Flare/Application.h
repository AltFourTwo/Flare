#pragma once

#include "Core.h"
#include "Logging/Console.h"

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
      Logging::Logger* m_Console;
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
   };

   // To be defined in client
   Application* Initialize();

}
