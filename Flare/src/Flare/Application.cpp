#include "FlarePCH.h"
#include "Application.h"

#include "Events/EventDispatcher.h"

// Temporary Includes
#include <GLFW/glfw3.h>
#include <glad/glad.h>

// Temporary no rendering code should be here ?
#include "Flare/Rendering/Renderer.h"

namespace Flare
{
#define BIND_EVENT_CALLBACK(cb) std::bind(&Application::cb, this, std::placeholders::_1)

   Application* Application::s_Instance = nullptr;

   /*****  C-TOR D-TOR  *****/
   Application::Application() :
      m_Console(),
      m_ResourceManager(),
      m_RenderingController()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of this application already exists!" ); // TODO more logs & error codes.
      s_Instance = this;

      m_MainWindow = std::unique_ptr<UserInterface::Window>( UserInterface::Window::Create( false ) );
      m_MainWindow->SetEventCallback( BIND_EVENT_CALLBACK( OnEvent ) );

      m_RenderingController.InitializePrimaryRenderer( Rendering::API::OpenGL, true );

      m_ImGuiLayer = new ProtoImGui::ImGuiLayer();
      m_LayerStack.PushOverlay( m_ImGuiLayer );
   }

   Application::~Application()
   {}

   /*****   FUNCTIONS   *****/
   void Application::Run()
   {
      while ( m_Running )
      {
         float x_Time = (float)glfwGetTime(); // TODO : This should be abstracted in a platform class ( Platform::GetTime() )
         Time::TimeStep x_TimeStep = x_Time - m_LastFrameTime;
         m_LastFrameTime = x_Time;

         //FLARE_CORE_INFO( "TimeStep is {0}s {1}ms", x_TimeStep.GetSeconds(), x_TimeStep.GetMilliseconds() );

         const Rendering::RendererCommandInterface& x_CommandInterface = m_RenderingController.GetRenderer().GetCommandInterface();
         x_CommandInterface.SetClearColor( { 0.5f, 0.25f, 0, 1 } );
         x_CommandInterface.Clear();

         if ( !m_Minimized || m_NoPauseOutsideFocus )
         {
            for ( UserInterface::Layer* x_Layer : m_LayerStack )
               x_Layer->OnUpdate( x_TimeStep );

            m_MainWindow->OnUpdate();
         }

         // TODO : Frame limit when out of focus
         // TODO : Should be in a render thread.
         if ( !m_Minimized )
         {
            for ( UserInterface::Layer* x_Layer : m_LayerStack )
               x_Layer->OnRender( x_TimeStep );

            m_MainWindow->OnRender();
         }

         m_ImGuiLayer->Begin();
         for ( UserInterface::Layer* x_Layer : m_LayerStack )
            x_Layer->OnImGuiRender();
         m_ImGuiLayer->End();
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

   /*****   EVENT HANDLERS   *****/
   void Application::OnEvent( Events::Event& e )
   {
      //FLARE_CORE_TRACE( e.ToString().c_str() );
      Events::EventDispatcher x_Dispatcher( e );
      x_Dispatcher.Dispatch<Events::WindowCloseEvent>( BIND_EVENT_CALLBACK( OnWindowClose) );
      x_Dispatcher.Dispatch<Events::WindowResizeEvent>( BIND_EVENT_CALLBACK( OnWindowResize ) );
      x_Dispatcher.Dispatch<Events::WindowFocusEvent>( BIND_EVENT_CALLBACK( OnWindowFocus ) );
      x_Dispatcher.Dispatch<Events::WindowLostFocusEvent>( BIND_EVENT_CALLBACK( OnWindowLostFocus ) );

      if ( e.IsHandled() )
         return;

      for ( UserInterface::LayerStack::LayerIterator_R itr = m_LayerStack.rbegin(); itr != m_LayerStack.rend(); )
      {
         ( *itr++ )->OnEvent( e );
         if ( e.IsHandled() )
            break;
      }

   }

   bool Application::OnWindowFocus( Events::WindowFocusEvent& e )
   {
      FLARE_CORE_INFO( e.GetName() );
      m_MainWindowFocused = true;
      return true;
   }

   bool Application::OnWindowLostFocus( Events::WindowLostFocusEvent& e )
   {
      FLARE_CORE_INFO( e.GetName() );
      m_MainWindowFocused = false;
      return true;
   }

   bool Application::OnWindowResize( Events::WindowResizeEvent& e )
   {
      FLARE_CORE_INFO( "W:{}, H:{}", e.GetWidth(), e.GetHeight() );
      if ( e.GetWidth() == 0 || e.GetHeight() == 0 )
      {
         m_Minimized = true;
         return false;
      }

      m_Minimized = false;
      m_RenderingController.GetRenderer().GetCommandInterface().SetViewport( 0, 0, e.GetWidth(), e.GetHeight() );
      return false;
   }

   bool Application::OnWindowClose( Events::WindowCloseEvent& e )
   {
      m_Running = false;
      return true;
   }
}
