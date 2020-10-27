#pragma once

namespace Flare::Configuration
{
   struct RENDERER_API_SCOPE
   {
      enum RendererAPI
      {
         None = 0,
         OpenGL = 1,
         DirectX = 2
      };
   };

   using RendererAPI = RENDERER_API_SCOPE::RendererAPI;
}