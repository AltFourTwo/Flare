#include "FlarePCH.h"
#include "PlatformUtils.h"
#include "Flare/Configuration/Configuration.h"

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Configuration::RendererAPI a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Configuration::RendererAPI::OpenGL:
            return std::move( UserInput::OpenGLKeyMap() );

         default:
            throw; // TODO : When the time comes, more KeyMaps can be added here.
      };
   }
}
