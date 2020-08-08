#pragma once

#include "Logging.h"
#include "Logger.h"
#include "LoggerParameters.h"
#include "Composing/Formattable.h"

namespace Logging
{
   using Formattable = Utility::Composing::Formattable;

   class Console
   {
      /*****   CLASS   FRIENDS      *****/
      friend class Logger;

      /*****   CLASS   CONSTANTS    *****/
      private:
      static const int MAX_LOGGERS = 16;

      /*****   CLASS   VARIABLES    *****/
      private:
      std::vector<Logger::SharedLogger> s_Loggers;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Console( const Console& ) = delete;

      private:
      Console();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Console& Instance();
      void Log( LogLevel a_LogLevel, const char* a_Message );
      void Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      void Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message );
      void Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      Logger::SharedLogger& CreateLogger( const LoggerParameters& a_Parameters ) noexcept;
      Logger::SharedLogger& CreateLogger( LoggerParameters&& a_Parameters ) noexcept;

      private: // These are meant for friend class Logger.
      void Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message );
      void Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );

      /*****   CLASS   OPERATORS    *****/
      void operator=( const Console& ) = delete;
   };
}