#pragma once
#include "Logging.h"
#include "LoggingContext.h"
#include "Flare/Core/SmartPointers.h"

#include <iostream>

namespace Flare::Logging
{
   class Logger;
   using SharedLogger = Ref<Logger>;

   class Logger
   {
      const char* DEFAULT_FORMAT = "{:M}";
      const LogLevel DEFAULT_LOG_LEVEL = LogLevel::Trace;

      /*****   VARIABLES   *****/
      private:
      bool m_Enabled = true;
      std::string m_LoggerName;
      std::string m_FormatString;
      LogLevel m_SeverityFilter;
      mutable std::chrono::system_clock::time_point m_LastMessageTimeStamp;

      /*****  C-TOR D-TOR  *****/
      private:
      Logger( const char* a_LoggerName ) noexcept;
      Logger( std::string&& a_LoggerName ) noexcept;

      public:
      virtual ~Logger() = default;

      /*****   FUNCTIONS   *****/
      public:
      void Enable() { m_Enabled = true; }
      void Disable() { m_Enabled = false; }

      static SharedLogger Create( const char* a_LoggerName = "Unnamed Logger" );
      static SharedLogger Create( std::string&& a_LoggerName );

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
      inline void Error( const char* a_Message, const Ts&... args )
      {
         Logger::Log( LogLevel::Error, a_Message, args... );
      }

      template<>
      inline void Error( const char* a_Message )
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
         if ( !m_Enabled || a_LogLevel < m_SeverityFilter )
            return;

         std::string x_Message = std::move( std::format( a_Message, args... ) );
         LoggingContext x_Context( *this, a_LogLevel, x_Message );
         std::cout << std::format( m_FormatString, x_Context );
         m_LastMessageTimeStamp = std::chrono::system_clock::now();
      }

      template<>
      void Log( const LogLevel& a_LogLevel, const char*& a_Message )
      {
         if ( !m_Enabled || a_LogLevel < m_SeverityFilter )
            return;

         std::string x_Message( a_Message );
         LoggingContext x_Context( *this, a_LogLevel, x_Message );
         std::cout << std::format( m_FormatString, x_Context );
         m_LastMessageTimeStamp = std::chrono::system_clock::now();
      }

      /*****   SETTERS   *****/
      public:
      inline void SetLoggingLevel( LogLevel a_LogLevel ) { m_SeverityFilter = a_LogLevel; }
      inline void SetFormatString( std::string&& a_FormatString ) { m_FormatString = std::move( a_FormatString ); }

      /*****   GETTERS   *****/
      public:
      inline LogLevel GetLoggingLevel() const { return m_SeverityFilter; }
      inline const std::string& GetName() const { return m_LoggerName; }
      inline const std::string& GetFormatString() const { return m_FormatString; }
      inline const std::chrono::system_clock::time_point& GetLastMessageTimeStamp() const { return m_LastMessageTimeStamp; }
   };
}
