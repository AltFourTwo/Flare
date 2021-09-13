#pragma once
#include "Flare/Core.h"
#include "Logging.h"
#include "LoggingContext.h"

#include <iostream>

namespace Flare::Logging
{
   class FLARE_API Logger
   {
      /*****   CONSTANTS   *****/
      public:
      static const char* DEFAULT_LOGGER_NAME;
      static const char* DEFAULT_FORMAT;
      static const LogLevel DEFAULT_LOG_LEVEL = LogLevel::Trace;

      /*****   VARIABLES   *****/
      private:
      std::string m_LoggerName;
      std::string m_FormatString;
      LogLevel m_BaseLoggingLevel;
      mutable std::chrono::system_clock::time_point m_LastMessageTimeStamp;

      /*****  C-TOR D-TOR  *****/
      public:
      Logger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const char* a_FormatString ) noexcept;
      Logger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept;
      Logger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept;
      Logger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept;
      Logger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept;

      /*****   FUNCTIONS   *****/
      public:
      template<typename... Ts>
      inline void Trace( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Trace, a_Message, args... );
      }

      template<>
      inline void Trace( const char* a_Message )
      {
         Logger::Log( LogLevel::Trace, a_Message );
      }

      template<typename... Ts>
      inline void Debug( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Debug, a_Message, args... );
      }

      template<>
      inline void Debug( const char* a_Message )
      {
         Logger::Log( LogLevel::Debug, a_Message );
      }

      template<typename... Ts>
      inline void Info( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Info, a_Message, args... );
      }

      template<>
      inline void Info( const char* a_Message )
      {
         Logger::Log( LogLevel::Info, a_Message );
      }

      template<typename... Ts>
      inline void Warn( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Warning, a_Message, args... );
      }

      template<>
      inline void Warn( const char* a_Message )
      {
         Logger::Log( LogLevel::Warning, a_Message );
      }

      template<typename... Ts>
      void Error( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Error, a_Message, args... );
      }

      template<>
      void Error( const char* a_Message )
      {
         Logger::Log( LogLevel::Error, a_Message );
      }

      template<typename... Ts>
      inline void Fatal( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Fatal, a_Message, args... );
      }

      template<>
      inline void Fatal( const char* a_Message )
      {
         Logger::Log( LogLevel::Fatal, a_Message );
      }

      private:
      template<typename... Ts>
      void Log( const LogLevel& a_LogLevel, const char*& a_Message, const Ts&... args )
      {
         if ( a_LogLevel >= m_BaseLoggingLevel )
         {
            std::string x_Message = std::move( std::format( a_Message, args... ) );
            LoggingContext x_Context( *this, a_LogLevel, x_Message );
            std::cout << std::format( m_FormatString, x_Context );
            m_LastMessageTimeStamp = std::chrono::system_clock::now();
         }
      }

      template<>
      void Log( const LogLevel& a_LogLevel, const char*& a_Message )
      {
         if ( a_LogLevel >= m_BaseLoggingLevel )
         {
            std::string x_Message( a_Message );
            LoggingContext x_Context( *this, a_LogLevel, x_Message );
            std::cout << std::format( m_FormatString, x_Context );
            m_LastMessageTimeStamp = std::chrono::system_clock::now();
         }
      }

      /*****   SETTERS   *****/
      public:
      inline void SetLoggingLevel( LogLevel a_LogLevel ) { m_BaseLoggingLevel = a_LogLevel; }
      inline void SetName( const std::string& a_Name ) { m_LoggerName = a_Name; }
      inline void SetName( std::string&& a_Name ) { m_LoggerName = std::move( a_Name ); }
      inline void SetFormatString( const std::string& a_FormatString ) { m_FormatString = a_FormatString; }
      inline void SetFormatString( std::string&& a_FormatString ) { m_FormatString = std::move( a_FormatString ); }

      /*****   GETTERS   *****/
      public:
      inline LogLevel GetLoggingLevel() const { return m_BaseLoggingLevel; }
      inline const std::string& GetName() const { return m_LoggerName; }
      inline const std::string& GetFormatString() const { return m_FormatString; }
      inline const std::chrono::system_clock::time_point& GetLastMessageTimeStamp() const { return m_LastMessageTimeStamp; }
   };
}