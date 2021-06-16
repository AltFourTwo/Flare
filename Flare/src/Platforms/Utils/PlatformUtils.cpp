#include "FlarePCH.h"
#include "PlatformUtils.h"

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

namespace Flare::UserInput
{
   KeyMap GetAPIKeyMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLKeyMap();

         default:
            throw; // TODO : When the time comes, more KeyMaps can be added here.
      };
   }

   ModifierMap GetAPIModifierMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLModifierMap();

         default:
            throw; // TODO : When the time comes, more ModifierMap can be added here.
      };
   }

   MouseMap GetAPIMouseMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLMouseMap();

         default:
            throw; // TODO : When the time comes, more MouseMaps can be added here.
      };
   }

   JoystickMap GetAPIJoystickMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLJoystickMap();

         default:
            throw; // TODO : When the time comes, more JoystickMap can be added here.
      };
   }

   GamePadMap GetAPIGamePadMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLGamePadMap();

         default:
            throw; // TODO : When the time comes, more GamePadMap can be added here.
      };
   }

   GamePadAxisMap GetAPIGamePadAxisMap( Rendering::API a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Rendering::API::OpenGL:
            return UserInput::OpenGLGamePadAxisMap();

         default:
            throw; // TODO : When the time comes, more GamePadAxisMap can be added here.
      };
   }
}
