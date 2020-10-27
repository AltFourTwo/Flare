#pragma once

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

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

   UserInput::KeyMap&& GetKeyMapForBackendAPI( RendererAPI a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case RendererAPI::OpenGL:
            return std::move( UserInput::OpenGLKeyMap() );

         default:
            throw; // TODO : When the time comes, more KeyMaps can be added here.
      };
   }
}