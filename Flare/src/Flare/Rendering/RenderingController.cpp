#include "FlarePCH.h"
#include "RenderingController.h"

#include "Renderer.h"

namespace Flare::Rendering
{
   RenderingController* RenderingController::s_Instance = nullptr;

   /*****  C-TOR D-TOR  *****/
   RenderingController::RenderingController() noexcept :
      m_PrimaryRenderer( nullptr ),
      m_SecondaryRenderer( nullptr ),
      m_CurrentRenderer( m_PrimaryRenderer )
   {}

   /*****   FUNCTIONS   *****/
   RenderingController& RenderingController::Initialize()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::RenderingController aleady exists!" ); // TODO more logs & error codes.
      s_Instance = new RenderingController();

      // Default for now.
      s_Instance->InitializePrimaryRenderer( Rendering::API::OpenGL, true );

      /*
      * Validate config.
      * If config contains valid primary renderer
      *    InitializePrimaryRenderer( API from config , true);
      * else
      *    Find appropriate renderer for system.
      *
      * If config contains valid secondary renderer
      *    InitializeSecondaryRenderer( API from config , false);
      */

      return *s_Instance;
   }

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
   Renderer& RenderingController::GetRenderer() { return *GetInstance().m_CurrentRenderer; }
   Renderer& RenderingController::GetPrimaryRenderer() { return *GetInstance().m_PrimaryRenderer; }
   Renderer& RenderingController::GetSecondaryRenderer() { return *GetInstance().m_SecondaryRenderer; }
   const API RenderingController::GetCurrentRendererUnderlyingAPI() { return GetRenderer().GetCommandInterfaceAPI(); }
   const API RenderingController::GetPrimaryRendererUnderlyingAPI() { return GetPrimaryRenderer().GetCommandInterfaceAPI(); }
   const API RenderingController::GetSecondaryRendererUnderlyingAPI() { return GetSecondaryRenderer().GetCommandInterfaceAPI(); }
}