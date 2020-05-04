#pragma once

#include "Flare/UserInterface/Window.h"

#include <GLFW/glfw3.h>

namespace Flare::UserInterface
{
   class WindowsWindow : public Window
   {
      /*****   NESTED  CLASSES      *****/
      private:
      struct WindowData
      {
         std::string Title;
         unsigned int Width, Height;
         bool VSync;
         EventCallback Callback;
      };

      /*****   CLASS   VARIABLES    *****/
      private:
      GLFWwindow* m_Window;
      WindowData m_WindowData;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      WindowsWindow(const WindowModel& a_Model);
      virtual ~WindowsWindow();

      /*****   CLASS   FUNCTIONS    *****/
      private:
      virtual void Init(const WindowModel& a_Model);
      virtual void Shutdown();

      public:
      void OnUpdate() override;

      /*****   SETTERS   *****/
      public:
      inline void SetEventCallback( const EventCallback& a_Callback ) override {}
      void SetVSync(bool a_value) override;

      /*****   GETTERS   *****/
      public:
      inline unsigned int GetWidth() const override { return 0; }
      inline unsigned int GetHeight() const override { return 0; }
      bool IsVSync() const override;
   };

}