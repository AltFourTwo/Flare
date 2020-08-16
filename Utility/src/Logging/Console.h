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
      static const int MAX_LOGGERS = 16; // TWEAK/CONFIG

      /*****   CLASS   VARIABLES    *****/
      private:
      std::vector<Logger::SharedLogger> s_Loggers;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Console( const Console& ) = delete;

      private:
      Console();

      /*****   CLASS   FUNCTIONS    *****/
      private:
      void Log( const char* a_Message );
      void Log( std::string& a_Message );

      public:
      void Log( LogLevel a_LogLevel, const char* a_Message );
      void Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      void Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message );
      void Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables );
      Logger::SharedLogger& CreateLogger( const LoggerParameters& a_Parameters ) noexcept;
      Logger::SharedLogger& CreateLogger( LoggerParameters&& a_Parameters ) noexcept;
      static Console& Instance();

      /*****   CLASS   OPERATORS    *****/
      void operator=( const Console& ) = delete;
   };
}