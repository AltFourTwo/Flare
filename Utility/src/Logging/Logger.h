#pragma once

#include <chrono>

#include "Composing/Formattable.h"
#include "Logging.h"

namespace Logging
{
   using Formattable = Utility::Composing::Formattable;

   /****************************\
   \*****   CLASS LOGGER   *****/
   class Logger
   {
      /**********************\
      \*****   NESTED   *****/
      private:
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
            AMPERSAND = 9,
            DATE_COMPILE_ERROR = 10,
            LOGGER_COMPILE_ERROR = 11
         };

         const char m_FormatChar;
         ActionType m_ActionType;
         std::string m_ReturnText;

         FormatAction( const ActionType&& a_ActionType, const char& a_FormatChar );
         FormatAction( const ActionType&& a_ActionType, LoggingControlCharacter&& a_FormatChar );
         FormatAction( const char*& a_TextStart, const size_t a_Length );

         std::string ExecuteAction( const Logger& a_Logger, const LogLevel& a_LogLevel, const char*& a_Message );
      };

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const char* m_LoggerName;
      LogLevel m_BaseLoggingLevel;
      int m_TextColor; // TODO Find a better type for color properties, int is a placeholder type.
      int m_BGColor;
      mutable std::vector<FormatAction> m_ExecutionQueue;
      mutable std::chrono::time_point<std::chrono::steady_clock> m_LastMessageTimeStamp;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Logger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      // Log Functions
      void Trace( const char* a_Message );
      void Debug( const char* a_Message );
      void Info( const char* a_Message );
      void Warn( const char* a_Message );
      void Error( const char* a_Message );
      void Fatal( const char* a_Message );
      void Trace( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void Debug( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void Info( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void Warn( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void Error( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void Fatal( const char* a_Message, const std::initializer_list<Formattable>& a_Formattables );

      std::string ExecuteQueue( const LogLevel& a_LogLevel, const char*& a_Message ) const;

      /***********************\
      \*****   SETTERS   *****/
      public:
      void SetBaseLoggingLevel( const LogLevel& a_LoggingLevel );
      void SetTextColor( const int& a_TextColor );
      void SetBackgroundColor( const int& a_BGColor );
      void SetFormat( const char* a_Format );

      /***********************\
      \*****   GETTERS   *****/
      const std::string GetName() const;

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void Log( const LogLevel& a_LogLevel, const char*& a_Message );
      void Log( const LogLevel& a_LogLevel, const char*& a_Message, const std::initializer_list<Formattable>& a_Formattables );
      void CompileFormat( std::vector<FormatAction>& a_ExecutionQueue, const char* a_LoggingFormat );
   };
}