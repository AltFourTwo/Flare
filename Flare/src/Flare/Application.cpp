#include "FlarePCH.h"

#include "Application.h"
#include "Events/EventDispatcher.h"

// Temporary Includes
#include "Composing/Composition.h"
#include <GLFW/glfw3.h>

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

         for (UserInterface::Layer* x_Layer : m_LayerStack )
            x_Layer->OnUpdate();

         m_MainWindow->OnUpdate();
      }
   }

   void Application::PopLayer( UserInterface::Layer* a_Layer )
   {
      m_LayerStack.PopLayer( a_Layer );
   }

   void Application::PushLayer( UserInterface::Layer* a_Layer )
   {
      m_LayerStack.PushLayer( a_Layer );
   }

   void Application::PopOverlay( UserInterface::Layer* a_Overlay )
   {
      m_LayerStack.PopOverlay( a_Overlay );
   }

   void Application::PushOverlay( UserInterface::Layer* a_Overlay )
   {
      m_LayerStack.PushOverlay( a_Overlay );
   }

   /*****   EVENT   HANDLERS     *****/
   void Application::OnEvent( Events::Event& e )
   {
      m_Console->Trace( e.ToString().c_str() );

      for ( UserInterface::LayerIterator_R itr = m_LayerStack.rend(); itr != m_LayerStack.rbegin(); )
      {
         (*itr++)->OnEvent(e);
         if (e.IsHandled())
            break;
      }

      Events::EventDispatcher x_Dispatcher( e );
      x_Dispatcher.Dispatch<Events::WindowCloseEvent>( BIND_EVENT_CALLBACK( OnWindowClose ) );
   }

   bool Application::OnWindowClose( Events::WindowCloseEvent& e )
   {
      m_Running = false;
      return true;
   }
}
