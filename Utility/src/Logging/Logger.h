#pragma once

#include "Composing/Formattable.h"
#include "Logging.h"

namespace Logging
{
   /****************************\
   \*****   CLASS LOGGER   *****/
   class Logger
   {
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