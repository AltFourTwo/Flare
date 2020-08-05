#include "FlarePCH.h"

#include "WindowsWindow.h"

#include "Logging/Console.h"

#include "Flare/Events/ApplicationEvent.h"
#include "Flare/Events/WindowEvent.h"
#include "Flare/Events/KeyEvent.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/EventDispatcher.h"

#include <glad/glad.h>

namespace Flare::UserInterface
{
   static void GLFWErrorCallback( int a_Error, const char* a_Desc );
   // TWEAK Might want to put GLFW initialization stuff outside window class/instanciation

   /*****   NAMESPACE   VARIABLES   *****/
   static bool s_GLFWInitialized = false;

   /*****   CLASS   C-TOR D-TOR  *****/
   WindowsWindow::WindowsWindow( const WindowModel& a_Model, const bool a_VSync ) :
      Window(),
      m_WindowData( a_Model, a_VSync )
   {
      Init( a_Model );
   }

   WindowsWindow::~WindowsWindow()
   {
      Shutdown();
   }

   /*****   CLASS   FUNCTIONS    *****/
   Window* Window::Create( const bool a_VSync, const WindowModel& a_Model ) { return new WindowsWindow( a_Model, a_VSync ); }

   void WindowsWindow::Init( const WindowModel& a_Model )
   {
      // LOG Window creation

      if ( !s_GLFWInitialized )
      {
         int x_Success = glfwInit();
         FLARE_CORE_ASSERT( x_Success );

         glfwSetErrorCallback( GLFWErrorCallback );

         s_GLFWInitialized = true;
      }

      m_Window = glfwCreateWindow( (int)a_Model.Width, (int)a_Model.Height, a_Model.Title.c_str(), nullptr, nullptr );
      glfwMakeContextCurrent( m_Window );

      int x_Status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
      FLARE_CORE_ASSERT( x_Status, "Failed to initialize Glad!");

      glfwSetWindowUserPointer( m_Window, &m_WindowData );
      SetVSync( m_WindowData.VSync );

      // GLFW Callbacks
      glfwSetWindowSizeCallback( m_Window, []( GLFWwindow* a_Window, int a_Width, int a_Height )
      {
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );
         x_Data.Width = a_Width;
         x_Data.Height = a_Height;

         Flare::Events::WindowResizeEvent x_Event( a_Width, a_Height );
         x_Data.Callback( x_Event );
      } );

      glfwSetWindowCloseCallback( m_Window, []( GLFWwindow* a_Window )
      {
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );
         Flare::Events::WindowCloseEvent x_Event;
         x_Data.Callback( x_Event );
      } );

      glfwSetKeyCallback( m_Window, []( GLFWwindow* a_Window, int a_Key, int a_ScanCode, int a_Action, int a_Mods )
      {
         // TODO define Flare Keycodes for abstraction.
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );

         switch ( a_Action )
         {
            case GLFW_PRESS:
            {
               Flare::Events::KeyPressedEvent x_Event( a_Key, 0 );
               x_Data.Callback( x_Event );
               break;
            }
            case GLFW_RELEASE:
            {
               Flare::Events::KeyReleasedEvent x_Event( a_Key );
               x_Data.Callback( x_Event );
               break;
            }
            case GLFW_REPEAT:
            {
               // TODO "It's possible to extract the reapeat count" Implement repeat count.
               // Possibly Seperate into distinct events.
               Flare::Events::KeyPressedEvent x_Event( a_Key, 1 );
               x_Data.Callback( x_Event );
               break;
            }
         }
      } );

      glfwSetMouseButtonCallback( m_Window, []( GLFWwindow* a_Window, int a_Button, int a_Action, int a_Mods )
      {
         // TODO define Flare Mousecodes for abstraction.
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );

         switch ( a_Action )
         {
            case GLFW_PRESS:
            {
               Flare::Events::MouseButtonPressedEvent x_Event( a_Button );
               x_Data.Callback( x_Event );
               break;
            }
            case GLFW_RELEASE:
            {
               Flare::Events::MouseButtonReleasedEvent x_Event( a_Button );
               x_Data.Callback( x_Event );
               break;
            }
         }
      } );

      glfwSetScrollCallback( m_Window, []( GLFWwindow* a_Window, double a_XOffset, double a_YOffset )
      {
         // TODO define Flare Mousecodes for abstraction.
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );

         Flare::Events::MouseScrolledEvent x_Event( (float)a_XOffset, (float)a_YOffset );
         x_Data.Callback( x_Event );
      } );

      glfwSetCursorPosCallback( m_Window, []( GLFWwindow* a_Window, double a_XPos, double a_YPos )
      {
         // TODO define Flare Mousecodes for abstraction.
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );

         Flare::Events::MouseMovedEvent x_Event( (float)a_XPos, (float)a_YPos );
         x_Data.Callback( x_Event );
      } );
   }

   void WindowsWindow::Shutdown()
   {
      glfwDestroyWindow( m_Window );
   }

   void WindowsWindow::OnUpdate()
   {
      glfwPollEvents();
   }

   void WindowsWindow::OnRender()
   {
      glfwSwapBuffers( m_Window );
   }

   static void GLFWErrorCallback( int a_Error, const char* a_Desc )
   {
      Logging::Console::Instance().Log( Logging::LogLevel::ERR_OR, "GLFW Error. Code [{0}] : {1}", { a_Error, a_Desc } );
   }

   /*****   GETTERS   *****/
   bool WindowsWindow::IsVSync() const
   {
      return m_WindowData.VSync;
   }

   /*****   SETTERS   *****/
   void WindowsWindow::SetVSync( bool a_Value )
   {
      if ( a_Value )
         glfwSwapInterval( 1 );
      else
         glfwSwapInterval( 0 );

      m_WindowData.VSync = a_Value;
   }
}