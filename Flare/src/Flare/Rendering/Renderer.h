#pragma once

#include "Flare/Configuration/Configuration.h"
#include "Flare/Rendering/ShaderDataTypeMap.h"

namespace Flare::Rendering
{
   class Renderer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static Configuration::RendererAPI s_RendererAPI;
      static ShaderDataTypeMap s_ShaderDataTypeMap;

      /*****   GETTERS   *****/
      public:
      inline static Configuration::RendererAPI CurrentAPI() { return s_RendererAPI; }
      inline static ShaderDataTypeMap GetShaderDataTypeMap() { return s_ShaderDataTypeMap; }
   };
}