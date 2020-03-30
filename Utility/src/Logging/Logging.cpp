#include "UtilityPCH.h"

#include "Logging.h"

namespace Logging
{
   bool IsDateControlCharacter( const char a_Char )
   {
      DateControlCharacter dcc = (DateControlCharacter)a_Char;

      switch ( dcc )
      {
         case DateControlCharacter::DCC_ABBREVIATED_WEEKDAY_NAME:                                         return true;
         case DateControlCharacter::DCC_FULL_WEEKDAY_NAME:                                                return true;
         case DateControlCharacter::DCC_ABBREVIATED_MONTH_NAME:                                           return true;
         case DateControlCharacter::DCC_FULL_MONTH_NAME:                                                  return true;
         case DateControlCharacter::DCC_DATE_AND_TIME_REPRESENTATION:                                     return true;
         case DateControlCharacter::DCC_YEAR_DIVIDED_BY_100_AND_TRUNCATED_TO_INTEGER:                     return true;
         case DateControlCharacter::DCC_DAY_OF_THE_MONTH_ZERO_PADDED:                                     return true;
         case DateControlCharacter::DCC_SHORT_MM_DD_YY_DATE:                                              return true;
         case DateControlCharacter::DCC_DAY_OF_THE_MONTH_SPACE_PADDED:                                    return true;
         case DateControlCharacter::DCC_SHORT_YYYY_MM_DD_DATE:                                            return true;
         case DateControlCharacter::DCC_WEEK_BASED_YEAR_LAST_TWO_DIGITS:                                  return true;
         case DateControlCharacter::DCC_WEEK_BASED_YEAR:                                                  return true;
         case DateControlCharacter::DCC_ABBREVIATED_MONTH_NAME_2:                                         return true;
         case DateControlCharacter::DCC_HOUR_IN_24H_FORMAT:                                               return true;
         case DateControlCharacter::DCC_HOUR_IN_12H_FORMAT:                                               return true;
         case DateControlCharacter::DCC_DAY_OF_THE_YEAR:                                                  return true;
         case DateControlCharacter::DCC_MONTH_AS_A_DECIMAL_NUMBER:                                        return true;
         case DateControlCharacter::DCC_MINUTE:                                                           return true;
         case DateControlCharacter::DCC_NEW_LINE_CHARACTER:                                               return true;
         case DateControlCharacter::DCC_AM_OR_PM_DESIGNATION:                                             return true;
         case DateControlCharacter::DCC_HOUR_CLOCK_TIME_12:                                               return true;
         case DateControlCharacter::DCC_HOUR_CLOCK_TIME_24:                                               return true;
         case DateControlCharacter::DCC_SECOND:                                                           return true;
         case DateControlCharacter::DCC_HORIZONTAL_TAB_CHARACTER:                                         return true;
         case DateControlCharacter::DCC_ISO_8601_TIME_FORMAT:                                             return true;
         case DateControlCharacter::DCC_ISO_8601_WEEKDAY_AS_NUMBER_WITH_MONDAY_AS_1:                      return true;
         case DateControlCharacter::DCC_WEEK_NUMBER_WITH_THE_FIRST_SUNDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateControlCharacter::DCC_ISO_8601_WEEK_NUMBER:                                             return true;
         case DateControlCharacter::DCC_WEEKDAY_AS_A_DECIMAL_NUMBER_WITH_SUNDAY_AS_0:                     return true;
         case DateControlCharacter::DCC_WEEK_NUMBER_WITH_THE_FIRST_MONDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateControlCharacter::DCC_DATE_REPRESENTATION:                                              return true;
         case DateControlCharacter::DCC_TIME_REPRESENTATION:                                              return true;
         case DateControlCharacter::DCC_YEAR_LAST_TWO_DIGITS:                                             return true;
         case DateControlCharacter::DCC_YEAR:                                                             return true;
         case DateControlCharacter::DCC_ISO_8601_OFFSET_FROM_UTC_IN_TIMEZONE:                             return true;
         case DateControlCharacter::DCC_TIMEZONE_NAME_OR_ABBREVIATION:                                    return true;
         case DateControlCharacter::DCC_A_PERCENTAGE_SIGN:                                                return true;
         default:                                                                   return false;
      }
   }

   bool IsLoggingControlCharacter( const char a_Char )
   {
      LoggingControlCharacter test5 = (LoggingControlCharacter)a_Char;

      switch ( test5 )
      {
         case LoggingControlCharacter::LCC_MESSAGE:       return true;
         case LoggingControlCharacter::LCC_LOG_LEVEL:     return true;
         case LoggingControlCharacter::LCC_LOGGER_NAME:   return true;
         case LoggingControlCharacter::LCC_AMPERSAND:     return true;
         case LoggingControlCharacter::LCC_SECONDS:       return true;
         case LoggingControlCharacter::LCC_MILLISECONDS:  return true;
         case LoggingControlCharacter::LCC_MICROSECONDS:  return true;
         case LoggingControlCharacter::LCC_NANOSECONDS:   return true;
         case LoggingControlCharacter::LCC_THREAD_ID:     return true;
         case LoggingControlCharacter::LCC_PROCESS_ID:    return true;
         default:                return false;
      }
   }
}