#include "FlarePCH.h"
#include "LogEmitter.h"
#include "LogService.h"

namespace Flare::Logging
{
   /*****  C-TOR D-TOR  *****/
   LogEmitter::LogEmitter( const char* a_LoggerName ) noexcept :
      m_Logger( LogService::GetInstance().CreateLogger( a_LoggerName ) )
   {}

   LogEmitter::LogEmitter( std::string&& a_LoggerName ) noexcept :
      m_Logger( LogService::GetInstance().CreateLogger( std::move( a_LoggerName ) ) )
   {}

   LogEmitter::LogEmitter( const LogEmitter& a_Other ) noexcept :
      m_Logger( a_Other.m_Logger )
   {}
}