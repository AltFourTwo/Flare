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

         WindowData( const WindowModel& a_Model, bool a_VSync = false ) :
            Title( a_Model.Title ),
            Width( a_Model.Width ),
            Height( a_Model.Height ),
            VSync( a_VSync )
         {}
      };

      /*****   CLASS   VARIABLES    *****/
      private:
      GLFWwindow* m_Window;
      WindowData m_WindowData;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      WindowsWindow( const WindowModel& a_Model, const bool a_VSync = false );
      virtual ~WindowsWindow();

      /*****   CLASS   FUNCTIONS    *****/
      private:
      virtual void Init( const WindowModel& a_Model );
      virtual void Shutdown();

      public:
      void OnUpdate() override;

      /*****   SETTERS   *****/
      public:
      inline void SetEventCallback( const EventCallback& a_Callback ) override { m_WindowData.Callback = a_Callback; }
      void SetVSync( bool a_value ) override;

      /*****   GETTERS   *****/
      public:
      inline virtual void* GetNativeWindow() const { return m_Window; };
      inline unsigned int GetWidth() const override { return m_WindowData.Width; }
      inline unsigned int GetHeight() const override { return m_WindowData.Height; }
      bool IsVSync() const override;
   };

}