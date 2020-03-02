#pragma once

#include "Composing/Formattable.h"
#include "Logging.h"

namespace Logging
{
   static const char* DEFAULT_LOGGER_NAME = "Unnamed Logger";
   static const std::string DEFAULT_FORMAT = "";
   static const int DEFAULT_BG_COLOR = 0;
   static const int DEFAULT_TEXT_COLOR = 0;

   class Logger
   {
      /***************************\
      \*****   ENUMERATORS   *****/
      enum LogLevel
      {
         TRACE = 1,
         DEBUG = 2,
         INFO = 3,
         WARNING = 4,
         ERROR = 5,
         FATAL = 6,
         OFF = 7
      };

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const char* m_LoggerName;
      const LogLevel m_BaseLoggingLevel;
      const int m_TextColor;
      const int m_BGColor;
      const std::string m_LoggingFormat;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Logger( const char*& a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const std::string& a_LoggingFormat );
      ~Logger();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      void Trace( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
      void Debug( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
      void Info( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
      void Warn( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
      void Error( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
      void Fatal( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void Log( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables );
   };
}