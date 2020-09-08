#include "FlarePCH.h"
#include "LogEmitter.h"
#include "Console.h"

namespace Flare::Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   // Base
   LogEmitterBase::LogEmitterBase( const LoggerParameters& a_Parameters ) noexcept :
      m_Logger( Console::Instance().CreateLogger( a_Parameters ) )
   {}

   LogEmitterBase::LogEmitterBase( LoggerParameters&& a_Parameters ) noexcept :
      m_Logger( Console::Instance().CreateLogger( std::forward<LoggerParameters>( a_Parameters ) ) )
   {}

   LogEmitterBase::LogEmitterBase( const LogEmitterBase& a_Other ) noexcept :
      m_Logger( a_Other.m_Logger )
   {}

   // Core Emitter
   CoreLogEmitter::CoreLogEmitter( const LoggerParameters& a_Parameters ) noexcept :
      LogEmitterBase( a_Parameters )
   {}

   CoreLogEmitter::CoreLogEmitter( LoggerParameters&& a_Parameters ) noexcept :
      LogEmitterBase( std::forward<LoggerParameters>( a_Parameters ) )
   {}

   CoreLogEmitter::CoreLogEmitter( const CoreLogEmitter& a_Other ) noexcept :
      LogEmitterBase( a_Other )
   {}

   // Client Emitter
   LogEmitter::LogEmitter( const LoggerParameters& a_Parameters ) noexcept :
      LogEmitterBase( a_Parameters )
   {}

   LogEmitter::LogEmitter( LoggerParameters&& a_Parameters ) noexcept :
      LogEmitterBase( std::forward<LoggerParameters>( a_Parameters ) )
   {}

   LogEmitter::LogEmitter( const LogEmitter& a_Other ) noexcept :
      LogEmitterBase( a_Other )
   {}
}