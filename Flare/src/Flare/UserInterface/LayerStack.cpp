#include "FlarePCH.h"
#include "LayerStack.h"

namespace Flare::UserInterface
{
   /*****   CLASS   C-TOR D-TOR  *****/
   LayerStack::LayerStack()
   {
      m_LayerInsert = m_Layers.begin();
   }

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
         m_Layers.erase(x_Layer);
         m_LayerInsert--;
      }
   }

   void LayerStack::PushLayer( Layer* a_Layer )
   {
      m_LayerInsert = m_Layers.emplace(m_LayerInsert, a_Layer);
   }

   void LayerStack::PopOverlay( Layer* a_Overlay )
   {
      LayerIterator_F x_Layer = std::find( m_Layers.begin(), m_Layers.end(), a_Overlay );
      if ( x_Layer != m_Layers.end() )
         m_Layers.erase( x_Layer );
   }

   void LayerStack::PushOverlay( Layer* a_Overlay )
   {
      m_Layers.emplace_back(a_Overlay);
   }
}
