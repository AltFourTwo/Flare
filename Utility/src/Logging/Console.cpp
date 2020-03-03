#include "UtilityPCH.h"

#include "Composing/Composition.h"
#include "Console.h"
#include "Logger.h"

namespace Logging
{
   /*************************\
   \*****   CONSTANTS   *****/
   const char* Console::DEFAULT_LOGGER_NAME = "Unnamed Logger";
   const std::string Console::DEFAULT_FORMAT = "";

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

   void Log( const char* a_Message )
   {
      printf( a_Message );
   }

   void Log( const Logger& a_Logger, const char* a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      std::string x_ComposedMessage = Composing::Format( a_Message, a_Formattables );

      printf( x_ComposedMessage.c_str() );
   }

   Logger& Console::Initialize( const char*& a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const std::string& a_LoggingFormat )
   {
      if ( m_IsInitialized )
         throw; // TODO Exception Logging System Already Initialized.

      m_Loggers.reserve( MAX_LOGGERS );
      m_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      m_IsInitialized = true;

      return m_Loggers.back();
   }

   Logger& Console::CreaterLogger( const char*& a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const std::string& a_LoggingFormat )
   {
      if ( !m_IsInitialized )
         throw; // TODO Exception Logging System Was Not Initialized.

      if ( m_Loggers.size() >= 16 )
         throw; // TODO Exception Maximum number of loggers hit.

      m_Loggers.emplace_back( a_LoggerName, a_BaseLoggingLevel, a_TextColor, a_BGColor, a_LoggingFormat );

      return m_Loggers.back();
   }
}