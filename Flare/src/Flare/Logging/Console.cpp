#include "FlarePCH.h"
#include "Console.h"
#include "Logger.h"

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

namespace Flare
{
   Console* Console::s_Instance = nullptr;

   /*****   CLASS   C-TOR D-TOR  *****/
   Console::Console() :
      m_ExtraLoggers()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::Console aleady exists!" ); // TODO more logs & error codes.
      s_Instance = this;

      m_ExtraLoggers.reserve( MAX_EXTRA_LOGGERS );
      m_CoreLogger = std::make_shared<Logging::Logger>( std::move( Logging::LoggerParameters( "Core", Logging::LogLevel::Trace, "[%T] &N : &M" ) ) );
      m_ClientLogger = std::make_shared<Logging::Logger>( std::move( Logging::LoggerParameters( "Client", Logging::LogLevel::Trace, "[%T] &N : &M" ) ) );
   }

   /*****   CLASS   FUNCTIONS    *****/
   Console::SharedLogger& Console::CreateLogger( const Logging::LoggerParameters& a_Parameters ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logging::Logger>( a_Parameters ) );
      return s_Instance->m_ExtraLoggers.back();
   }

   Console::SharedLogger& Console::CreateLogger( Logging::LoggerParameters&& a_Parameters ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logging::Logger>( std::forward<Logging::LoggerParameters>( a_Parameters ) ) );
      return s_Instance->m_ExtraLoggers.back();
   }
}