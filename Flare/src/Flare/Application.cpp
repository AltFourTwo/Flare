#include "FlarePCH.h"
#include "Application.h"

#include "Events/EventDispatcher.h"

// Temporary Includes
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "UserInput/Input.h"

namespace Flare
{
#define BIND_EVENT_CALLBACK(cb) std::bind(&Application::cb, this, std::placeholders::_1)

   Application* Application::s_Instance = nullptr;
   Logging::Logger::SharedLogger Application::s_ClientLogger = nullptr;

   /*****   CLASS   C-TOR D-TOR  *****/
   Application::Application() :
      LogEmitter( Logging::LoggerParameters( "Core", Logging::LogLevel::TRACE, "%F at %T | &N says : &M" ) )
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of this application aleady exists!" );
      s_Instance = this;

      //s_ClientLogger = Logging::Console::Instance().CreateLogger( Logging::LoggerParameters( "App", Logging::LogLevel::TRACE, "%F at %T | &N says : &M" ) );

      //s_ClientLogger->Trace

      m_MainWindow = std::unique_ptr<UserInterface::Window>( UserInterface::Window::Create( false ) );
      m_MainWindow->SetEventCallback( BIND_EVENT_CALLBACK( OnEvent ) );
   }

   Application::~Application()
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void Application::Run()
   {
      while ( m_Running )
      {
         float x_Time = (float)glfwGetTime(); // TODO : This should be abstracted in a platform class ( Platform::GetTime() )
         Time::TimeStep x_TimeStep = x_Time - m_LastFrameTime;
         m_LastFrameTime = x_Time;

         //FLARE_CORE_INFO( "TimeStep is {0}s {1}ms", { x_TimeStep.GetSeconds(), x_TimeStep.GetMilliseconds() } );

         glClearColor( 0.5f, 0.25f, 0, 1 );
         glClear( GL_COLOR_BUFFER_BIT );

         for ( UserInterface::Layer* x_Layer : m_LayerStack )
            x_Layer->OnUpdate( x_TimeStep );

         m_MainWindow->OnUpdate();

         //auto [x, y] = UserInput::Input::GetMousePosition();
         //FLARE_CORE_TRACE( "{0}, {1}", { x, y } );

         for ( UserInterface::Layer* x_Layer : m_LayerStack )
            x_Layer->OnRender( x_TimeStep );

         m_MainWindow->OnRender();
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
      //FLARE_CORE_TRACE( e.ToString().c_str() );

      for ( UserInterface::LayerIterator_R itr = m_LayerStack.rbegin(); itr != m_LayerStack.rend(); )
      {
         ( *itr++ )->OnEvent( e );
         if ( e.IsHandled() )
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
