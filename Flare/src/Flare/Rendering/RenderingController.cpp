#include "FlarePCH.h"
#include "RenderingController.h"

#include "Flare/Application.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   RenderingController::RenderingController() :
      m_PrimaryRenderer( nullptr ),
      m_SecondaryRenderer( nullptr ),
      m_CurrentRenderer( m_PrimaryRenderer )
   {}

   RenderingController::~RenderingController()
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void RenderingController::SwapRenderers()
   {
      if ( m_PrimaryRenderer == nullptr || m_SecondaryRenderer == nullptr )
         throw; // TODO Exception : Can't use swap when a renderer is not set.

      if ( m_CurrentRenderer == m_PrimaryRenderer )
         m_CurrentRenderer = m_SecondaryRenderer;
      else
         m_CurrentRenderer = m_PrimaryRenderer;
   }

   void RenderingController::InitializePrimaryRenderer( Rendering::API a_API, bool a_SetCurrent )
   {
      m_PrimaryRenderer = std::make_shared<Renderer>( a_API );

      if ( a_SetCurrent )
         m_CurrentRenderer = m_PrimaryRenderer;

      m_PrimaryRenderer->Init();
   }

   void RenderingController::InitializeSecondaryRenderer( Rendering::API a_API, bool a_SetCurrent )
   {
      m_SecondaryRenderer = std::make_shared<Renderer>( a_API );

      if ( a_SetCurrent )
         m_CurrentRenderer = m_SecondaryRenderer;

      m_SecondaryRenderer->Init();
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