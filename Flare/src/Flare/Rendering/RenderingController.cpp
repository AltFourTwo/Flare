#include "FlarePCH.h"
#include "RenderingController.h"

#include "Flare/Application.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   RenderingController* RenderingController::s_Instance = nullptr;

   /*****  C-TOR D-TOR  *****/
   RenderingController::RenderingController() :
      m_PrimaryRenderer( nullptr ),
      m_SecondaryRenderer( nullptr ),
      m_CurrentRenderer( m_PrimaryRenderer )
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::RenderingController aleady exists!" ); // TODO more logs & error codes.
      s_Instance = this;
   }

   /*****   FUNCTIONS   *****/
   void RenderingController::SwitchRenderers()
   {
      if ( m_PrimaryRenderer == nullptr || m_SecondaryRenderer == nullptr )
         throw; // TODO Exception : Can't use swap when a renderer is not set.

      if ( m_CurrentRenderer == m_PrimaryRenderer )
         m_CurrentRenderer = m_SecondaryRenderer;
      else
         m_CurrentRenderer = m_PrimaryRenderer;
   }

   void RenderingController::InitializeRenderer( Ref<Renderer>& a_Renderer, API a_API, bool a_SetCurrent )
   {
      a_Renderer = std::make_shared<Renderer>( a_API );

      if ( a_SetCurrent )
         m_CurrentRenderer = a_Renderer;

      a_Renderer->Init();
   }

   void RenderingController::InitializePrimaryRenderer( API a_API, bool a_SetCurrent )
   {
      InitializeRenderer( m_PrimaryRenderer, a_API, a_SetCurrent );
   }

   void RenderingController::InitializeSecondaryRenderer( API a_API, bool a_SetCurrent )
   {
      InitializeRenderer( m_SecondaryRenderer, a_API, a_SetCurrent );
   }

   /*****   GETTERS   *****/
   Renderer& RenderingController::GetRenderer()
   {
      return *Application::GetRenderingController().m_CurrentRenderer;
   }

   Renderer& RenderingController::GetPrimaryRenderer()
   {
      return *Application::GetRenderingController().m_PrimaryRenderer;
   }

   Renderer& RenderingController::GetSecondaryRenderer()
   {
      return *Application::GetRenderingController().m_SecondaryRenderer;
   }

   const API RenderingController::GetCurrentRendererUnderlyingAPI()
   {
      return Application::GetRenderingController().m_CurrentRenderer->GetCommandInterfaceAPI();
   }

   const API RenderingController::GetPrimaryRendererUnderlyingAPI()
   {
      return Application::GetRenderingController().m_PrimaryRenderer->GetCommandInterfaceAPI();
   }

   const API RenderingController::GetSecondaryRendererUnderlyingAPI()
   {
      return Application::GetRenderingController().m_SecondaryRenderer->GetCommandInterfaceAPI();
   }
}