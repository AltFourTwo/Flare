#include "FlarePCH.h"
#include "Logging.h"

namespace Flare::Logging
{
   /*****   NAMESPACE   FUNCTIONS   *****/
   bool IsLoggingControlCharacter( const char a_Char )
   {
      LoggingControlCharacter x_LCC = static_cast<LoggingControlCharacter>(a_Char);

      switch ( x_LCC )
      {
         case LoggingControlCharacter::UNDEFINED:              return true;
         case LoggingControlCharacter::MESSAGE:                return true;
         case LoggingControlCharacter::LOG_LEVEL_L:            return true;
         case LoggingControlCharacter::LOG_LEVEL_U:            return true;
         case LoggingControlCharacter::LOGGER_NAME:            return true;
         case LoggingControlCharacter::ELAPSED_SECONDS:        return true;
         case LoggingControlCharacter::ELAPSED_MILLISECONDS:   return true;
         case LoggingControlCharacter::ELAPSED_MICROSECONDS:   return true;
         case LoggingControlCharacter::ELAPSED_NANOSECONDS:    return true;
         case LoggingControlCharacter::THREAD_ID:              return true;
         case LoggingControlCharacter::ERROR_LCC:              return true;
         default:                                              return false;
      }
   }

   LoggingControlCharacter ConvertToLoggingControlCharacter( const char a_Char )
   {
      LoggingControlCharacter x_LCC = static_cast<LoggingControlCharacter>( a_Char );

      switch ( x_LCC )
      {
         case LoggingControlCharacter::UNDEFINED:              return x_LCC;
         case LoggingControlCharacter::MESSAGE:                return x_LCC;
         case LoggingControlCharacter::LOG_LEVEL_L:            return x_LCC;
         case LoggingControlCharacter::LOG_LEVEL_P:            return x_LCC;
         case LoggingControlCharacter::LOG_LEVEL_U:            return x_LCC;
         case LoggingControlCharacter::LOGGER_NAME:            return x_LCC;
         case LoggingControlCharacter::ELAPSED:                return x_LCC;
         case LoggingControlCharacter::ELAPSED_SECONDS:        return x_LCC;
         case LoggingControlCharacter::ELAPSED_MILLISECONDS:   return x_LCC;
         case LoggingControlCharacter::ELAPSED_MICROSECONDS:   return x_LCC;
         case LoggingControlCharacter::ELAPSED_NANOSECONDS:    return x_LCC;
         case LoggingControlCharacter::TIME:                   return x_LCC;
         case LoggingControlCharacter::THREAD_ID:              return x_LCC;
         case LoggingControlCharacter::ERROR_LCC:              return x_LCC;
         default:                                              return LoggingControlCharacter::ERROR_LCC;
      }
   }
}