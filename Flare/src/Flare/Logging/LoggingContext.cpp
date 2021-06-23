#include "FlarePCH.h"
#include "LoggingContext.h"

namespace Flare::Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   LoggingContext::LoggingContext( const Logger& a_Logger, LogLevel a_LogLevel, const std::string& a_Message ) :
      m_Logger( a_Logger ),
      m_LogLevel( a_LogLevel ),
      m_Message( a_Message ),
      m_LogTime( std::chrono::system_clock::now() )
   {}
}

typename std::format_parse_context::iterator std::formatter<Flare::Logging::LoggingContext>::parse( std::format_parse_context& a_ParseContext )
{
   return a_ParseContext.begin();
}

typename std::format_context::iterator std::formatter<Flare::Logging::LoggingContext>::format( Flare::Logging::LoggingContext a_LoggingContext, std::format_context& a_FormatContext )
{
   return a_FormatContext.out();
}