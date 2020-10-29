#include "FlarePCH.h"
#include "PlatformUtils.h"
#include "Flare/Configuration/Configuration.h"

#include "Flare/UserInput/InputMaps.h"
#include "Platforms/OpenGL/OpenGLInputMaps.h"

#include "Flare/Rendering/ShaderDataTypeMap.h"
#include "Platforms/OpenGL/OpenGLShaderDataTypeMap.h"

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

namespace Flare::Rendering
{
   ShaderDataTypeMap&& GetAPIDataTypeMap( Configuration::RendererAPI a_ConfigValue )
   {
      switch ( a_ConfigValue )
      {
         case Configuration::RendererAPI::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            throw; // TODO Exception.

         case Configuration::RendererAPI::OpenGL:
            return std::move( OpenGLShaderDataTypeMap() );
      }

      FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
      throw;
   }
}