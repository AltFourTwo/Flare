#pragma once
#include "RendererInterface.h"

namespace Flare::Rendering
{
   class RendererCommandInterface
   {
      /*****   VARIABLES   *****/
      private:
      Ref<RendererInterface> m_Interface;

      /*****  C-TOR D-TOR  *****/
      public:
      RendererCommandInterface(API a_RenderingAPI);

      /*****   FUNCTIONS   *****/
      public:
      inline void Init()
      {
         m_Interface->Init();
      }

      inline void Clear() const
      {
         m_Interface->Clear();
      }

      inline void SetClearColor( const glm::vec4& a_Color ) const
      {
         m_Interface->SetClearColor( a_Color );
      }

      inline void DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray ) const
      {
         m_Interface->DrawIndexed( a_VertexArray );
      }

      /*****   GETTERS   *****/
      public:
      inline const RendererInterface& GetInterface() const
      {
         return *m_Interface;
      }

      inline const API GetInterfaceAPI() const
      {
         return m_Interface->GetAPI();
      }
   };
}