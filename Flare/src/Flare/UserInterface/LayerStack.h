#pragma once

#include "Flare/Core.h"
#include "Layer.h"

#include <vector>

namespace Flare::UserInterface
{
   class FLARE_API LayerStack
   {
      // TODO : Make Iterator using & typedef standards.
      public:
      using LayerIterator_F = std::vector<Layer*>::iterator;
      using LayerIterator_R = std::vector<Layer*>::reverse_iterator;

      /*****   VARIABLES   *****/
      private:
      std::vector<Layer*> m_Layers;
      unsigned int m_LayerInsertIndex = 0;

      /*****  C-TOR D-TOR  *****/
      public:
      LayerStack();
      ~LayerStack();

      /*****   FUNCTIONS   *****/
      public:
      void PopLayer(Layer* a_Layer);
      void PushLayer(Layer* a_Layer);
      void PopOverlay(Layer* a_Overlay);
      void PushOverlay(Layer* a_Overlay);

      /*****   GETTERS   *****/
      public:
      LayerIterator_F begin() { return m_Layers.begin(); }
      LayerIterator_F end() { return m_Layers.end(); }
      LayerIterator_R rbegin() { return m_Layers.rbegin(); }
      LayerIterator_R rend() { return m_Layers.rend(); }
   };
}