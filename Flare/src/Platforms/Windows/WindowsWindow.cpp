#include "FlarePCH.h"

#include "WindowsInput.h"
#include "WindowsWindow.h"

#include "Flare/Logging/Console.h"
#include "Flare/Events/ApplicationEvent.h"
#include "Flare/Events/WindowEvent.h"
#include "Flare/Events/KeyEvent.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/EventDispatcher.h"
#include "Platforms/Utils/PlatformUtils.h"

#include <glad/glad.h>

namespace Flare::UserInterface
{
   static void GLFWErrorCallback( int a_Error, const char* a_Desc );
   // TWEAK Might want to put GLFW initialization stuff outside window class/instanciation

   /*****   NAMESPACE   VARIABLES   *****/
   static bool s_GLFWInitialized = false;

   /*****  C-TOR D-TOR  *****/
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

   /*****   FUNCTIONS   *****/
   Window* Window::Create( const bool a_VSync, const WindowModel& a_Model ) { return new WindowsWindow( a_Model, a_VSync ); }

   void WindowsWindow::Init( const WindowModel& a_Model )
   {
      LOG_TRACE( "WindowsWindow Init!" );

      if ( !s_GLFWInitialized )
      {
         int x_Success = glfwInit();
         FLARE_CORE_ASSERT( x_Success ); // TODO more logs & error codes.

         glfwSetErrorCallback( GLFWErrorCallback );

         s_GLFWInitialized = true;
      }

      if ( UserInput::WindowsInput::Initialize<UserInput::WindowsInput>( Rendering::API::OpenGL ) )
      {
         LOG_TRACE( "Input scheme initialized and tied to window!" );
         SetInputScheme( UserInput::WindowsInput::GetInstance() );
      }
      else
      {
         LOG_TRACE( "Input scheme already initialized! Tying existing scheme to window." );
         SetInputScheme( UserInput::WindowsInput::GetInstance() );
      }

      m_Window = glfwCreateWindow( (int)a_Model.Width, (int)a_Model.Height, a_Model.Title.c_str(), nullptr, nullptr );
      glfwMakeContextCurrent( m_Window );

      int x_Status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
      FLARE_CORE_ASSERT( x_Status, "Failed to initialize Glad!" ); // TODO more logs & error codes.

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

      glfwSetCharCallback( m_Window, []( GLFWwindow* a_Window, unsigned int a_Char )
      {
         WindowData& x_Data = *(WindowData*)glfwGetWindowUserPointer( a_Window );
         Flare::Events::KeyTypedEvent x_Event( a_Char );

         x_Data.Callback( x_Event );
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

      std::cout << (const char*)glGetString( GL_VERSION ) << std::endl;

      glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
      glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
      glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

      LOG_TRACE( "WindowsWindow Init Completed!" );
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
      FLARE_CORE_ERROR( "GLFW Error. Code [{0}] : {1}", a_Error, a_Desc ); // TODO more logs & error codes.
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