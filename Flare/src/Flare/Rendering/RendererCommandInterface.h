#pragma once
#include "RendererInterface.h"

namespace Flare::Rendering
{
   class RendererCommandInterface
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      Ref<RendererInterface> m_Interface;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      RendererCommandInterface(API a_RenderingAPI);

      /*****   CLASS   FUNCTIONS    *****/
      inline void  Init()
      {
         m_Interface->Init();
      }

      inline const RendererInterface& GetInterface() const
      {
         return *m_Interface;
      }

      inline const API GetInterfaceAPI() const
      {
         return m_Interface->GetAPI();
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
   };
}