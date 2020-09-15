#include "FlarePCH.h"
#include "LayerStack.h"

namespace Flare::UserInterface
{
   /*****   CLASS   C-TOR D-TOR  *****/
   LayerStack::LayerStack() {}

   LayerStack::~LayerStack()
   {
      for (Layer* x_Layer : m_Layers )
         delete x_Layer;
   }

   /*****   CLASS   FUNCTIONS    *****/
   void LayerStack::PopLayer( Layer* a_Layer )
   {
      LayerIterator_F x_Layer = std::find(m_Layers.begin(), m_Layers.end(), a_Layer);
      if ( x_Layer != m_Layers.end() )
      {
         a_Layer->OnDetach();
         m_Layers.erase(x_Layer);
         m_LayerInsertIndex--;
      }
   }

   void LayerStack::PushLayer( Layer* a_Layer )
   {
      m_Layers.emplace( m_Layers.begin() + m_LayerInsertIndex, a_Layer);
      m_LayerInsertIndex++;
      a_Layer->OnAttach();
   }

   void LayerStack::PopOverlay( Layer* a_Overlay )
   {
      LayerIterator_F x_Layer = std::find( m_Layers.begin(), m_Layers.end(), a_Overlay );
      if ( x_Layer != m_Layers.end() )
      {
         a_Overlay->OnDetach();
         m_Layers.erase( x_Layer );
      }
   }

   void LayerStack::PushOverlay( Layer* a_Overlay )
   {
      m_Layers.emplace_back(a_Overlay);
      a_Overlay->OnAttach();
   }
}
