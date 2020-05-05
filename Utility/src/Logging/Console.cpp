#include "UtilityPCH.h"

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

#include "Composing/Composition.h"
#include "Console.h"
#include "Logger.h"

namespace Logging
{
   using Formattable = Utility::Composing::Formattable;

   /*************************\
   \*****   CONSTANTS   *****/
   const char* Console::DEFAULT_LOGGER_NAME = "Unnamed Logger";
   const char* Console::DEFAULT_FORMAT = "";

   /*****   CLASS   VARIABLES    *****/
   bool Console::s_IsInitialized = false;
   std::vector<Logger> Console::s_Loggers = std::vector<Logger>();

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
      Log( Get().s_Loggers.front(), a_LogLevel, a_Message );
   }

   void Console::Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables )
   {
      Log( Get().s_Loggers.front(), a_LogLevel, a_Message, a_Formattables );
   }

   // Log message using a logger's information.
   void Console::Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message )
   {
      std::string x_ConsoleFormattedMessage = a_Logger.ExecuteQueue( a_LogLevel, a_Message );
      std::cout << x_ConsoleFormattedMessage << "\n";
   }

   void Console::Log( const Logger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables )
   {
      std::string x_ComposedMessage = Format( a_Message, a_Formattables );
      Log( a_Logger, a_LogLevel, x_ComposedMessage.c_str() );
   }

   // Returns the first logger for core logging.
   Logger& Console::Initialize( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat )
   {
      if ( s_IsInitialized )
         throw; // TODO Exception Logging System Already Initialized.

      s_Loggers.reserve( MAX_LOGGERS );
      s_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      s_IsInitialized = true;

      return s_Loggers.back();
   }

   Logger& Console::CreateLogger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat )
   {
      if ( !s_IsInitialized )
         throw; // TODO Exception Logging System Was Not Initialized.

      if ( s_Loggers.size() >= MAX_LOGGERS )
         throw; // TODO Exception Maximum number of loggers hit.

      s_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      return s_Loggers.back();
   }
}