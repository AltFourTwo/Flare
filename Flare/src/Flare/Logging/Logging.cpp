#include "FlarePCH.h"
#include "Logging.h"

namespace Flare::Logging
{
   /*****   NAMESPACE   FUNCTIONS   *****/
   bool IsDateControlCharacter( const char a_Char )
   {
      DateTimeControlCharacter x_DTCC = (DateTimeControlCharacter)a_Char;

      switch ( x_DTCC )
      {
         case DateTimeControlCharacter::ABBREVIATED_WEEKDAY_NAME:                                         return true;
         case DateTimeControlCharacter::FULL_WEEKDAY_NAME:                                                return true;
         case DateTimeControlCharacter::ABBREVIATED_MONTH_NAME:                                           return true;
         case DateTimeControlCharacter::FULL_MONTH_NAME:                                                  return true;
         case DateTimeControlCharacter::DATE_AND_TIME_REPRESENTATION:                                     return true;
         case DateTimeControlCharacter::YEAR_DIVIDED_BY_100_AND_TRUNCATED_TO_INTEGER:                     return true;
         case DateTimeControlCharacter::DAY_OF_THE_MONTH_ZERO_PADDED:                                     return true;
         case DateTimeControlCharacter::SHORT_MM_DD_YY_DATE:                                              return true;
         case DateTimeControlCharacter::DAY_OF_THE_MONTH_SPACE_PADDED:                                    return true;
         case DateTimeControlCharacter::SHORT_YYYY_MM_DD_DATE:                                            return true;
         case DateTimeControlCharacter::WEEK_BASED_YEAR_LAST_TWO_DIGITS:                                  return true;
         case DateTimeControlCharacter::WEEK_BASED_YEAR:                                                  return true;
         case DateTimeControlCharacter::ABBREVIATED_MONTH_NAME_2:                                         return true;
         case DateTimeControlCharacter::HOUR_IN_24H_FORMAT:                                               return true;
         case DateTimeControlCharacter::HOUR_IN_12H_FORMAT:                                               return true;
         case DateTimeControlCharacter::DAY_OF_THE_YEAR:                                                  return true;
         case DateTimeControlCharacter::MONTH_AS_A_DECIMAL_NUMBER:                                        return true;
         case DateTimeControlCharacter::MINUTE:                                                           return true;
         case DateTimeControlCharacter::NEW_LINE_CHARACTER:                                               return true;
         case DateTimeControlCharacter::AM_OR_PM_DESIGNATION:                                             return true;
         case DateTimeControlCharacter::HOUR_CLOCK_TIME_12:                                               return true;
         case DateTimeControlCharacter::HOUR_CLOCK_TIME_24:                                               return true;
         case DateTimeControlCharacter::SECOND:                                                           return true;
         case DateTimeControlCharacter::HORIZONTAL_TAB_CHARACTER:                                         return true;
         case DateTimeControlCharacter::ISO_8601_TIME_FORMAT:                                             return true;
         case DateTimeControlCharacter::ISO_8601_WEEKDAY_AS_NUMBER_WITH_MONDAY_AS_1:                      return true;
         case DateTimeControlCharacter::WEEK_NUMBER_WITH_THE_FIRST_SUNDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateTimeControlCharacter::ISO_8601_WEEK_NUMBER:                                             return true;
         case DateTimeControlCharacter::WEEKDAY_AS_A_DECIMAL_NUMBER_WITH_SUNDAY_AS_0:                     return true;
         case DateTimeControlCharacter::WEEK_NUMBER_WITH_THE_FIRST_MONDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE:   return true;
         case DateTimeControlCharacter::DATE_REPRESENTATION:                                              return true;
         case DateTimeControlCharacter::TIME_REPRESENTATION:                                              return true;
         case DateTimeControlCharacter::YEAR_LAST_TWO_DIGITS:                                             return true;
         case DateTimeControlCharacter::YEAR:                                                             return true;
         case DateTimeControlCharacter::ISO_8601_OFFSET_FROM_UTC_IN_TIMEZONE:                             return true;
         case DateTimeControlCharacter::TIMEZONE_NAME_OR_ABBREVIATION:                                    return true;
         case DateTimeControlCharacter::A_PERCENTAGE_SIGN:                                                return true;
         default:                                                                                         return false;
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
         default:                                     return false;
      }
   }
}