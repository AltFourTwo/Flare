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

   /*****   CLASS   C-TOR D-TOR  *****/
   Console::Console() :
      s_Loggers()
   {
      s_Loggers.reserve( MAX_LOGGERS );
   }

   /*****   CLASS   FUNCTIONS    *****/
   Console& Console::Instance()
   {
      static Console s_Instance;
      return s_Instance;
   }

   // Not specifying a logger uses the first one in the list which should always be the core logger.
   void Console::Log( LogLevel a_LogLevel, const char* a_Message )
   {
      Log( s_Loggers.front(), a_LogLevel, a_Message );
   }

   void Console::Log( LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables )
   {
      Log( s_Loggers.front(), a_LogLevel, a_Message, a_Formattables );
   }

   // Log message using a logger's information.
   void Console::Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message )
   {
      std::string x_ConsoleFormattedMessage = a_Logger->ExecuteQueue( a_LogLevel, a_Message );
      std::cout << x_ConsoleFormattedMessage << "\n";
   }

   void Console::Log( const Logger::SharedLogger& a_Logger, LogLevel a_LogLevel, const char* a_Message, std::initializer_list<Formattable> a_Formattables )
   {
      std::string x_ComposedMessage = Format( a_Message, a_Formattables );
      Log( a_Logger, a_LogLevel, x_ComposedMessage.c_str() );
   }

   // These 2 log functions are meant for friend class Logger.
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

   Logger::SharedLogger& Console::CreateLogger( const LoggerParameters& a_Parameters ) noexcept
   {
      s_Loggers.emplace_back( std::make_shared<Logger>( a_Parameters ) );

      return s_Loggers.back();
   }

   Logger::SharedLogger& Console::CreateLogger( LoggerParameters&& a_Parameters ) noexcept
   {
      s_Loggers.emplace_back( std::make_shared<Logger>( std::move( a_Parameters ) ) );

      return s_Loggers.back();
   }
}