#pragma once

#include "Composing/Formattable.h"
#include "Logging.h"

namespace Logging
{
   /****************************\
   \*****   CLASS LOGGER   *****/
   class Logger
   {
      /**********************\
      \*****   NESTED   *****/
      private:
      struct FormatAction
      {
         enum ReturnType
         {
            FORMATTED_DATE = 1,
            LOGGER_INFO = 2,
            JUST_TEXT = 3
         };
         char m_FormatChar;
         ReturnType m_ReturnType;
         std::string m_ReturnText;

         FormatAction( const ReturnType& a_ReturnType, const char& a_FormatChar );
         FormatAction( const std::string& a_Text );
      };

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const char* m_LoggerName;
      LogLevel m_BaseLoggingLevel;
      int m_TextColor; // TODO Find a better type for color properties, int is a placeholder type.
      int m_BGColor;
      std::queue<FormatAction, class queue> m_ExecutionQueue;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Logger( const char*& a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const std::string& a_LoggingFormat );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      // Log Functions
      void Trace( const char*& a_Message );
      void Debug( const char*& a_Message );
      void Info( const char*& a_Message );
      void Warn( const char*& a_Message );
      void Error( const char*& a_Message );
      void Fatal( const char*& a_Message );
      void Trace( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void Debug( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void Info( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void Warn( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void Error( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void Fatal( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );

      /***********************\
      \*****   SETTERS   *****/
      public:
      void SetBaseLoggingLevel( const LogLevel& a_LoggingLevel );
      void SetTextColor( const int& a_TextColor );
      void SetBackgroundColor( const int& a_BGColor );
      void SetFormat( const std::string& a_Format );

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void Log( const LogLevel& a_LogLevel, const char*& a_Message );
      void Log( const LogLevel& a_LogLevel, const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables );
      void CompileFormat( std::queue<FormatAction, class queue>& a_ExecutionQueue, const std::string& a_LoggingFormat );
   };
}