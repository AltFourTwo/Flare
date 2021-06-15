#pragma once

#include "Flare/Core.h"
#include "Logging.h"
#include "LoggerParameters.h"

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>

namespace Flare::Logging
{
   class FLARE_API Logger
   {
      /*****   NESTED  CLASSES      *****/
      private:
      struct LoggingContext
      {
         const Logger& m_Logger;
         const Logging::LogLevel m_LogLevel;
         const std::string& m_FormattedMessage;
      };

      struct FormatAction
      {
         enum class ActionType : int
         {
            SIMPLE_TEXT = 1,
            FORMAT_DATE = 2,
            LOGGER_NAME = 3,
            LOG_LEVEL = 4,
            LOG_MESSAGE = 5,
            LOG_TIME_DIFFERENCE = 6,
            LOG_PROCESS_ID = 7,
            LOG_THREAD_ID = 8,
            DATE_COMPILE_ERROR = 9,
            LOGGER_COMPILE_ERROR = 10
         };

         const char m_FormatChar;
         ActionType m_ActionType;
         std::string m_ReturnText;

         FormatAction( ActionType a_ActionType, char a_FormatChar );
         FormatAction( ActionType a_ActionType, LoggingControlCharacter a_FormatChar );
         FormatAction( const char* a_TextStart, size_t a_Length );

         void Execute( const LoggingContext& a_Context, std::string& /* out */ a_ReturnText );
      };

      /*****   CLASS   VARIABLES    *****/
      private:
      LoggerParameters m_Parameters;
      std::vector<FormatAction> m_ActionQueue;
      mutable std::chrono::time_point<std::chrono::steady_clock> m_LastMessageTimeStamp;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Logger( const LoggerParameters& a_Parameters ) noexcept;
      Logger( LoggerParameters&& a_Parameters ) noexcept;

      /*****   CLASS   FUNCTIONS    *****/
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

      template<typename... Ts>
      inline std::string PrepareMessage( LogLevel a_LogLevel, const char* a_Message, const Ts&... args ) const
      {
         LoggingContext x_Context
         {
            *this,
            a_LogLevel,
            std::format( a_Message, args... ),
         };

         return ExecuteQueue( x_Context ); // TODO : Use move semantics.
      };

      template<>
      inline std::string PrepareMessage( LogLevel a_LogLevel, const char* a_Message ) const
      {
         LoggingContext x_Context
         {
            *this,
            a_LogLevel,
            a_Message,
         };

         return ExecuteQueue( x_Context ); // TODO : Use move semantics.
      };

      private:
      void CompileFormat( const char* a_LoggingFormat );
      std::string ExecuteQueue( const LoggingContext& a_Context ) const;

      template<typename... Ts>
      void Log( const LogLevel& a_LogLevel, const char*& a_Message, const Ts&... args )
      {
         if ( a_LogLevel >= m_Parameters.m_BaseLoggingLevel )
            std::cout << PrepareMessage( a_LogLevel, a_Message, args... );
      }

      template<>
      void Log( const LogLevel& a_LogLevel, const char*& a_Message )
      {
         if ( a_LogLevel >= m_Parameters.m_BaseLoggingLevel )
            std::cout << PrepareMessage( a_LogLevel, a_Message );
      }

      /*****   SETTERS   *****/
      public:
      void SetParameters( LoggerParameters&& a_Parameters );

      /*****   GETTERS   *****/
      public:
      const LoggerParameters& GetParameters() const;
   };
}