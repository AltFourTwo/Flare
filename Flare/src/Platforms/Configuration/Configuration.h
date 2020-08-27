#pragma once

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

namespace Flare::Configuration
{
   struct BACKEND_API_SCOPE
   {
      enum BackendAPI
      {
         OpenGL = 0,
         DirectX = 1
      };
   };

   using BackendAPI = BACKEND_API_SCOPE::BackendAPI;

   UserInput::KeyMap&& GetKeyMapForBackendAPI( BackendAPI a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case BackendAPI::OpenGL:
            return UserInput::OpenGLKeyMap();

         default:
            throw; // TODO : When the time comes, more KeyMaps can be added here.
      };
   }
}