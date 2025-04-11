#pragma once

namespace Flare::Logging
{
   /*****   NAMESPACE   CONSTANTS   *****/
   enum class LogLevel : int
   {
      Trace = 0,
      Debug = 1,
      Info = 2,
      Warning = 3,
      Error = 4,
      Fatal = 5,
      Off = 6
   };

   static const char* LogLevelNamesLower[] = { "trace", "debug", "info", "warning", "error", "fatal","off" };
   static const char* LogLevelNamesPascal[] = { "Trace", "Debug", "Info", "Warning", "Error", "Fatal","Off" };
   static const char* LogLevelNamesUpper[] = { "TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "FATAL","OFF" };
   static const char* TimeUnits[] = { "s", "ms", "us", "ns" };

   // TODO Implement Thread ID.
   enum class LoggingControlCharacter : char
   {
      UNDEFINED = '!',              // Uninitialized default value.
      MESSAGE = 'M',                // The actual message to log.
      LOG_LEVEL_L = 'L',            // The severity of the message in lower case.
      LOG_LEVEL_P = 'P',            // The severity of the message in pascal case.
      LOG_LEVEL_U = 'U',            // The severity of the message in upper case.
      LOGGER_NAME = 'N',            // The logger that is used to log the message.
      ESCAPE_SEQUENCE = 'E',
      FOREGROUND_COLOR = 'F',
      BACKGROUND_COLOR = 'B',
      ELAPSED = 'e',                // Displays the time since the last message from the logger in it's most significant unit.
      ELAPSED_SECONDS = 's',        // The number of seconds since the last message from the logger. 
      ELAPSED_MILLISECONDS = 'm',   // The number of milliseconds since the last message from the logger.
      ELAPSED_MICROSECONDS = 'u',   // The number of microseconds since the last message from the logger.
      ELAPSED_NANOSECONDS = 'n',    // The number of nanoseconds since the last message from the logger.
      TIME = 'T',                   // The time of instanciation of the context upon logging.
      PROCESS_ID = 'p',             // The process ID used by ? Where ? Leaving unimplemented for now.
      THREAD_ID = 't',              // The thread ID used by ? Where ? Leaving unimplemented for now.
      ERROR_LCC = '?'               // Error Character.
   };

   /*****   NAMESPACE   FUNCTIONS   *****/
   bool IsLoggingControlCharacter( const char a_Char );
   LoggingControlCharacter ConvertToLoggingControlCharacter( const char a_Char );
}
