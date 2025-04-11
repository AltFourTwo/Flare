#include "FlarePCH.h"
#include "Logger.h"

namespace Flare::Logging
{
   /*****  C-TOR D-TOR  *****/
   Logger::Logger( const char* a_LoggerName ) noexcept :
      m_LoggerName( a_LoggerName ),
      m_SeverityFilter( LogLevel::Trace ),
      m_FormatString( "{:M}" )
   {}

   Logger::Logger( std::string&& a_LoggerName ) noexcept :
      m_LoggerName( std::move( a_LoggerName ) ),
      m_SeverityFilter( LogLevel::Trace ),
      m_FormatString( "{:M}" )
   {}

   /*****   FUNCTIONS   *****/
   SharedLogger Logger::Create( const char* a_LoggerName )
   {
      return SharedLogger( new Logger( a_LoggerName ) );
   }

   SharedLogger Logger::Create( std::string&& a_LoggerName )
   {
      return SharedLogger( new Logger( std::move( a_LoggerName ) ) );
   }
}
