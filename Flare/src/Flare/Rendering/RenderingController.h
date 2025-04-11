#pragma once
#include "Rendering.h"

#include "Flare/Core/SmartPointers.h"

namespace Flare::Rendering
{
   class Renderer;

   class RenderingController
   {
      /*****   VARIABLES   *****/
      private:
      static RenderingController* s_Instance;
      Ref<Renderer> m_PrimaryRenderer = nullptr;
      Ref<Renderer> m_SecondaryRenderer = nullptr;
      Ref<Renderer> m_CurrentRenderer = m_PrimaryRenderer;

      /*****  C-TOR D-TOR  *****/
      private:
      RenderingController() noexcept;
      ~RenderingController() = default;

      public:
      RenderingController( const RenderingController& ) = delete;

      /*****   FUNCTIONS   *****/
      public:
      static RenderingController& Initialize();
      void InitializePrimaryRenderer( API a_API, bool a_SetCurrent = false );
      void InitializeSecondaryRenderer( API a_API, bool a_SetCurrent = false );
      void SwitchRenderers();

      private:
      void InitializeRenderer( Ref<Renderer>& a_Renderer, API a_API, bool a_SetCurrent );

      /*****   OPERATORS    *****/
      public:
      void operator=( const RenderingController& ) = delete;

      /*****   GETTERS   *****/
      public:
      inline static const RenderingController& GetInstance() { return *s_Instance; }
      static Renderer& GetRenderer();
      static Renderer& GetPrimaryRenderer();
      static Renderer& GetSecondaryRenderer();
      static const API GetCurrentRendererUnderlyingAPI();
      static const API GetPrimaryRendererUnderlyingAPI();
      static const API GetSecondaryRendererUnderlyingAPI();
   };
}