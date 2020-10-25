#include "FlarePCH.h"
#include "LogEmitter.h"
#include "Console.h"

namespace Flare::Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   // Base
   LogEmitter::LogEmitter( const LoggerParameters& a_Parameters ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( a_Parameters ) )
   {}

   LogEmitter::LogEmitter( LoggerParameters&& a_Parameters ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( std::forward<LoggerParameters>( a_Parameters ) ) )
   {}

   LogEmitter::LogEmitter( const LogEmitter& a_Other ) noexcept :
      m_Logger( a_Other.m_Logger )
   {}
}