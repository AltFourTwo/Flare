#pragma once

#include "Flare/Configuration/Configuration.h"

namespace Flare::Rendering
{
   class Renderer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static Configuration::RendererAPI s_RendererAPI;


      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline static Configuration::RendererAPI CurrentAPI() { return s_RendererAPI; }
   };
}