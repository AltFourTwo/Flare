#pragma once
#include "Rendering.h"

namespace Flare::Rendering
{
   class Renderer;

   class RenderingController
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      Ref<Renderer> m_PrimaryRenderer = nullptr;
      Ref<Renderer> m_SecondaryRenderer = nullptr;
      Ref<Renderer> m_CurrentRenderer = m_PrimaryRenderer; // Should be a ref?

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      RenderingController();
      ~RenderingController();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void InitializePrimaryRenderer( Rendering::API a_API, bool a_SetCurrent = false );
      void InitializeSecondaryRenderer( Rendering::API a_API, bool a_SetCurrent = false );
      void SwapRenderers();

      /*****   GETTERS   *****/
      public:
      static Renderer& GetRenderer();
      static Renderer& GetPrimaryRenderer();
      static Renderer& GetSecondaryRenderer();
      static const API GetCurrentRendererUnderlyingAPI();
      static const API GetPrimaryRendererUnderlyingAPI();
      static const API GetSecondaryRendererUnderlyingAPI();
   };
}