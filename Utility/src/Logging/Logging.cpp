#include "UtilityPCH.h"

#include "Logging.h"

namespace Logging
{
   bool IsDateControlCharacter( const char a_Char )
   {
      DateControlCharacter x_DCC = (DateControlCharacter)a_Char;

      switch ( x_DCC )
      {
         case DateControlCharacter::ABBREVIATED_WEEKDAY_NAME:                                         return true;
         case DateControlCharacter::FULL_WEEKDAY_NAME:                                                return true;
         case DateControlCharacter::ABBREVIATED_MONTH_NAME:                                           return true;
         case DateControlCharacter::FULL_MONTH_NAME:                                                  return true;
         case DateControlCharacter::DATE_AND_TIME_REPRESENTATION:                                     return true;
         case DateControlCharacter::YEAR_DIVIDED_BY_100_AND_TRUNCATED_TO_INTEGER:                     return true;
         case DateControlCharacter::DAY_OF_THE_MONTH_ZERO_PADDED:                                     return true;
         case DateControlCharacter::SHORT_MM_DD_YY_DATE:                                              return true;
         case DateControlCharacter::DAY_OF_THE_MONTH_SPACE_PADDED:                                    return true;
         case DateControlCharacter::SHORT_YYYY_MM_DD_DATE:                                            return true;
         case DateControlCharacter::WEEK_BASED_YEAR_LAST_TWO_DIGITS:                                  return true;
         case DateControlCharacter::WEEK_BASED_YEAR:                                                  return true;
         case DateControlCharacter::ABBREVIATED_MONTH_NAME_2:                                         return true;
         case DateControlCharacter::HOUR_IN_24H_FORMAT:                                               return true;
         case DateControlCharacter::HOUR_IN_12H_FORMAT:                                               return true;
         case DateControlCharacter::DAY_OF_THE_YEAR:                                                  return true;
         case DateControlCharacter::MONTH_AS_A_DECIMAL_NUMBER:                                        return true;
         case DateControlCharacter::MINUTE:                                                           return true;
         case DateControlCharacter::NEW_LINE_CHARACTER:                                               return true;
         case DateControlCharacter::AM_OR_PM_DESIGNATION:                                             return true;
         case DateControlCharacter::HOUR_CLOCK_TIME_12:                                               return true;
         case DateControlCharacter::HOUR_CLOCK_TIME_24:                                               return true;
         case DateControlCharacter::SECOND:                                                           return true;
         case DateControlCharacter::HORIZONTAL_TAB_CHARACTER:                                         return true;
         case DateControlCharacter::ISO_8601_TIME_FORMAT:                                             return true;
         case DateControlCharacter::ISO_8601_WEEKDAY_AS_NUMBER_WITH_MONDAY_AS_1:                      return true;
         case DateControlCharacter::WEEK_NUMBER_WITH_THE_FIRST_SUNDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateControlCharacter::ISO_8601_WEEK_NUMBER:                                             return true;
         case DateControlCharacter::WEEKDAY_AS_A_DECIMAL_NUMBER_WITH_SUNDAY_AS_0:                     return true;
         case DateControlCharacter::WEEK_NUMBER_WITH_THE_FIRST_MONDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateControlCharacter::DATE_REPRESENTATION:                                              return true;
         case DateControlCharacter::TIME_REPRESENTATION:                                              return true;
         case DateControlCharacter::YEAR_LAST_TWO_DIGITS:                                             return true;
         case DateControlCharacter::YEAR:                                                             return true;
         case DateControlCharacter::ISO_8601_OFFSET_FROM_UTC_IN_TIMEZONE:                             return true;
         case DateControlCharacter::TIMEZONE_NAME_OR_ABBREVIATION:                                    return true;
         case DateControlCharacter::A_PERCENTAGE_SIGN:                                                return true;
         default:                                                                   return false;
      }
   }

   bool IsLoggingControlCharacter( const char a_Char )
   {
      LoggingControlCharacter x_LCC = (LoggingControlCharacter)a_Char;

      switch ( x_LCC )
      {
         case LoggingControlCharacter::MESSAGE:       return true;
         case LoggingControlCharacter::LOG_LEVEL:     return true;
         case LoggingControlCharacter::LOGGER_NAME:   return true;
         case LoggingControlCharacter::AMPERSAND:     return true;
         case LoggingControlCharacter::SECONDS:       return true;
         case LoggingControlCharacter::MILLISECONDS:  return true;
         case LoggingControlCharacter::MICROSECONDS:  return true;
         case LoggingControlCharacter::NANOSECONDS:   return true;
         case LoggingControlCharacter::THREAD_ID:     return true;
         case LoggingControlCharacter::PROCESS_ID:    return true;
         case LoggingControlCharacter::ERROR_LCC:     return true;
         default:                return false;
      }
   }
}