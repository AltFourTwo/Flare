#include "FlarePCH.h"
#include "PlatformUtils.h"

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return std::move( UserInput::OpenGLKeyMap() );

         default:
            throw; // TODO : When the time comes, more KeyMaps can be added here.
      };
   }
}
