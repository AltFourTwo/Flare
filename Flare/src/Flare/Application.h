#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "UserInterface/Window.h"

namespace Flare
{
   class FLARE_API Application
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      std::unique_ptr<UserInterface::Window> m_Window;
      bool m_Running = true;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Application();
      virtual ~Application();

      /*****   CLASS   FUNCTIONS    *****/
      void Run();
      void Test();


   };

   // To be defined in client
   Application* Initialize();

}
