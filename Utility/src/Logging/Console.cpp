#include "UtilityPCH.h"

#include <string>
#include <vector>
#include <initializer_list>

#include "Composing/Composition.h"
#include "Console.h"
#include "Logger.h"

namespace Logging
{
   /*************************\
   \*****   CONSTANTS   *****/
   const char* Console::DEFAULT_LOGGER_NAME = "Unnamed Logger";
   const char* Console::DEFAULT_FORMAT = "";

   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Console::Console()
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   Console& Console::Get()
   {
      static Console instance;
      return instance;
   }

   // Not specifying a logger uses the first one in the list from initialization.
   void Console::Log( LogLevel a_LogLevel, const char* a_Message )
   {
      Log( Get().m_Loggers.front(), a_LogLevel, a_Message );
   }

   void Console::Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      Log( Get().m_Loggers.front(), a_LogLevel, a_Message, a_Formattables );
   }

   // Log message using a logger's information.
   void Console::Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message )
   {
      std::string x_ConsoleFormattedMessage = a_Logger.ExecuteQueue( a_LogLevel, a_Message );
      printf( x_ConsoleFormattedMessage.c_str() );
   }

   void Console::Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      std::string x_ComposedMessage = Composing::Format( a_Message, a_Formattables );
      Log( a_Logger, a_LogLevel, x_ComposedMessage.c_str() );
   }

   // Returns the first logger for core logging.
   Logger& Console::Initialize( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat )
   {
      if ( m_IsInitialized )
         throw; // TODO Exception Logging System Already Initialized.

      m_Loggers.reserve( MAX_LOGGERS );
      m_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      m_IsInitialized = true;

      return m_Loggers.back();
   }

   Logger& Console::CreaterLogger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat )
   {
      if ( !m_IsInitialized )
         throw; // TODO Exception Logging System Was Not Initialized.

      if ( m_Loggers.size() >= MAX_LOGGERS )
         throw; // TODO Exception Maximum number of loggers hit.

      m_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      return m_Loggers.back();
   }
}