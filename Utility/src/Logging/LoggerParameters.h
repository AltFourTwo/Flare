#pragma once

#include "Logging/Logging.h"

namespace Logging
{
   struct LoggerParameters
   {
      /*****   CLASS   CONSTANTS    *****/
      static const char* DEFAULT_LOGGER_NAME;
      static const char* DEFAULT_FORMAT;
      static const int DEFAULT_BG_COLOR = 0;
      static const int DEFAULT_TEXT_COLOR = 0;
      static const LogLevel DEFAULT_LOG_LEVEL = Logging::LogLevel::TRACE;

      /*****   CLASS   VARIABLES    *****/
      const char* m_LoggerName;
      const char* m_FormatString;
      LogLevel m_BaseLoggingLevel;
      int m_TextColor; // TODO Find a better type for color properties, int is a placeholder type.
      int m_BackgroundColor;

      /*****   CLASS   C-TOR D-TOR  *****/
      LoggerParameters( const char* a_LoggerName = DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = DEFAULT_LOG_LEVEL, const char* a_FormatString = DEFAULT_FORMAT, const int& a_TextColor = DEFAULT_TEXT_COLOR, const int& a_BackgroundColor = DEFAULT_BG_COLOR );
      LoggerParameters( const LoggerParameters& a_Other );
      LoggerParameters( LoggerParameters&& a_Other ) noexcept;
      ~LoggerParameters() noexcept {};

      /*****   CLASS   OPERATORS    *****/
      LoggerParameters& operator=( LoggerParameters&& a_Parameters ) noexcept;
   };
}