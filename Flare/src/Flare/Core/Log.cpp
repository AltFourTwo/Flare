#include "FlarePCH.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Flare
{
   std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
   std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

   Log::Log()
   {

   }

   Log::~Log()
   {

   }

   void Log::Init()
   {
      spdlog::set_pattern( "[%H:%M] [%^%l%$] %n : %v" );

      s_CoreLogger = spdlog::stdout_color_mt( "Flare" );
      s_CoreLogger->set_level( spdlog::level::trace );
      s_ClientLogger = spdlog::stdout_color_mt( "App" );
      s_ClientLogger->set_level( spdlog::level::trace );
   }
}