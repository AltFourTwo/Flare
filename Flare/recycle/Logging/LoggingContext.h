#pragma once
#include "Logging.h"

#include <string>
#include <chrono>
#include <format>

namespace Flare::Logging
{
   class Logger;

   struct LoggingContext
   {
      /*****   VARIABLES   *****/
      const Logger& m_Logger;
      const LogLevel m_LogLevel;
      const std::string& m_Message;
      const std::chrono::system_clock::time_point m_LogTime;

      /*****  C-TOR D-TOR  *****/
      LoggingContext( const Logger& a_Logger, LogLevel a_LogLevel, const std::string& a_Message );
   };
}

template<>
class std::formatter<Flare::Logging::LoggingContext>
{
   /*****   VARIABLES   *****/
   private:
   Flare::Logging::LoggingControlCharacter m_Indicator = Flare::Logging::LoggingControlCharacter::UNDEFINED;
   std::string m_SubFormat = "";

   /*****   FUNCTIONS   *****/
   public:
   typename std::format_parse_context::iterator parse( std::format_parse_context& a_ParseContext );
   typename std::format_context::iterator format( Flare::Logging::LoggingContext a_LoggingContext, std::format_context& a_FormatContext );
};
