#include "FlarePCH.h"

#include "Application.h"
#include "Events/EventDispatcher.h"

// Temporary Includes
#include "Test/TestObject.h"
#include "Composing/Composition.h"
#include "Exceptions/UtilityException.h"
#include <GLFW/glfw3.h>
#include <random>

#include <cstdint>

#include <thread>
#include <exception>

namespace Flare
{
#define BIND_EVENT_CALLBACK(cb) std::bind(&Application::cb, this, std::placeholders::_1)

   /*****   CLASS   C-TOR D-TOR  *****/
   Application::Application()
   {
      m_Console = &Logging::Console::Get().Initialize( "Core", Logging::LogLevel::TRACE, 0, 0, "%F at %T | &N says : &M" );
      m_MainWindow = std::unique_ptr<UserInterface::Window>( UserInterface::Window::Create() );
      m_MainWindow->SetEventCallback( BIND_EVENT_CALLBACK( OnEvent ) );
   }

   Application::~Application()
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void Application::Run()
   {
      while ( m_Running )
      {
         glClearColor( 0.5f, 0.25f, 0, 1 );
         glClear( GL_COLOR_BUFFER_BIT );

         m_MainWindow->OnUpdate();
      }
   }

   /*****   EVENT   HANDLERS     *****/
   void Application::OnEvent( Events::Event& e )
   {
      m_Console->Trace( e.ToString().c_str() );

      Events::EventDispatcher x_Dispatcher( e );
      x_Dispatcher.Dispatch<Events::WindowCloseEvent>( BIND_EVENT_CALLBACK( OnWindowClose ) );
   }

   bool Application::OnWindowClose( Events::WindowCloseEvent& e )
   {
      m_Running = false;
      return true;
   }
}
