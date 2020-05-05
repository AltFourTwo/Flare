#pragma once

#include "Core.h"
#include "Logging/Console.h"
#include "UserInterface/Window.h"
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
      std::unique_ptr<UserInterface::Window> m_MainWindow;
      bool m_Running = true;
      Logging::Logger* m_Console;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Application();
      virtual ~Application();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void Run();

      /*****   EVENT   HANDLERS     *****/
      private:
      void OnEvent(Events::Event& e);
      bool OnWindowClose(Events::WindowCloseEvent& e);
   };

   // To be defined in client
   Application* Initialize();

}
