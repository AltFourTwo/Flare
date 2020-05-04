#include "FlarePCH.h"

#include "WindowsWindow.h"

namespace Flare::UserInterface
{
   // TWEAK Might want to put GLFW initialization stuff outside window class/instanciation

   /*****   NAMESPACE   VARIABLES   *****/
   static bool s_GLFWInitialized = false;

   /*****   CLASS   C-TOR D-TOR  *****/
   WindowsWindow::WindowsWindow( const WindowModel& a_Model )
   {
      Init( a_Model );
   }

   WindowsWindow::~WindowsWindow()
   {
      Shutdown();
   }

   /*****   CLASS   FUNCTIONS    *****/
   Window* Window::Create( const WindowModel& a_Model )
   {
      return new WindowsWindow( a_Model );
   }

   void WindowsWindow::Init( const WindowModel& a_Model )
   {
      m_WindowData.Title = a_Model.Title;
      m_WindowData.Width = a_Model.Width;
      m_WindowData.Height = a_Model.Height;

      // LOG Window creation

      if ( !s_GLFWInitialized )
      {
         int x_Success = glfwInit();
         FLARE_CORE_ASSERT( x_Success );

         s_GLFWInitialized = true;
      }

      m_Window = glfwCreateWindow( (int)a_Model.Width, (int)a_Model.Height, a_Model.Title.c_str(), nullptr, nullptr );
      glfwMakeContextCurrent(m_Window);
      glfwSetWindowUserPointer(m_Window, &m_WindowData);
      SetVSync(true);
   }

   void WindowsWindow::Shutdown()
   {
      glfwDestroyWindow( m_Window );
   }

   void WindowsWindow::OnUpdate()
   {
      glfwPollEvents();
      glfwSwapBuffers(m_Window);
   }

   void WindowsWindow::SetVSync( bool a_Value )
   {
      if (a_Value)
         glfwSwapInterval(1);
      else
         glfwSwapInterval(0);

      m_WindowData.VSync = a_Value;
   }

   bool WindowsWindow::IsVSync() const
   {
      return m_WindowData.VSync;
   }
}