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

   /*****   CLASS   C-TOR D-TOR  *****/
   Application::Application() :
      m_Console(),
      m_ResourceManager(),
      m_RenderingController()
   {
      FLARE_CORE_ASSERT( !s_Instance, { "An instance of this application aleady exists!" } );
      s_Instance = this;

      // ( *m_Console.GetCoreLogger() ).SetParameters( Logging::LoggerParameters( "Core", Logging::LogLevel::Trace, "%F at %T | &N says : &M" ) );

      m_MainWindow = std::unique_ptr<UserInterface::Window>( UserInterface::Window::Create( false ) );
      m_MainWindow->SetEventCallback( BIND_EVENT_CALLBACK( OnEvent ) );

      m_RenderingController.InitializePrimaryRenderer( Rendering::API::OpenGL, true );

      m_ImGuiLayer = new ProtoImGui::ImGuiLayer();
      m_LayerStack.PushOverlay( m_ImGuiLayer );
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

         const Rendering::RendererCommandInterface& x_CommandInterface = m_RenderingController.GetRenderer().GetCommandInterface();
         x_CommandInterface.SetClearColor( { 0.5f, 0.25f, 0, 1 } );
         x_CommandInterface.Clear();

         for ( UserInterface::Layer* x_Layer : m_LayerStack )
            x_Layer->OnUpdate( x_TimeStep );

         m_MainWindow->OnUpdate();

         //auto [x, y] = UserInput::Input::GetMousePosition();
         //FLARE_CORE_TRACE( "{0}, {1}", { x, y } );

         // TODO : Should be in a render thread.
         m_ImGuiLayer->Begin();
         for ( UserInterface::Layer* x_Layer : m_LayerStack )
         {
            x_Layer->OnRender( x_TimeStep );
            x_Layer->OnImGuiRender();
         }
         m_ImGuiLayer->End();

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

      for ( UserInterface::LayerStack::LayerIterator_R itr = m_LayerStack.rbegin(); itr != m_LayerStack.rend(); )
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
