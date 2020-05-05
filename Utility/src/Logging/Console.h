#pragma once

#include "Logging.h"
#include "Logger.h"
#include "Composing/Formattable.h"

namespace Logging
{
   using Formattable = Utility::Composing::Formattable;

   class Console
   {
      /*************************\
      \*****   CONSTANTS   *****/
      private:
      static const char* DEFAULT_LOGGER_NAME;
      static const char* DEFAULT_FORMAT;
      static const int DEFAULT_BG_COLOR = 0;
      static const int DEFAULT_TEXT_COLOR = 0;
      static const int MAX_LOGGERS = 16;
      static const Logging::LogLevel DEFAULT_LOG_LEVEL = Logging::LogLevel::TRACE;

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      static bool s_IsInitialized;
      static std::vector<Logger> s_Loggers;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      private:
      Console();
      Console( const Console& ) = delete;

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      static Console& Get();
      static void Log( LogLevel a_LogLevel, const char* a_Message );
      static void Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      static void Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message );
      static void Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      static Logger& Initialize( const char* a_LoggerName = DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = DEFAULT_LOG_LEVEL, const int& a_TextColor = DEFAULT_TEXT_COLOR, const int& a_BGColor = DEFAULT_BG_COLOR, const char* a_LoggingFormat = DEFAULT_FORMAT );
      static Logger& CreateLogger( const char* a_LoggerName = DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = DEFAULT_LOG_LEVEL, const int& a_TextColor = DEFAULT_TEXT_COLOR, const int& a_BGColor = DEFAULT_BG_COLOR, const char* a_LoggingFormat = DEFAULT_FORMAT );
   };
}