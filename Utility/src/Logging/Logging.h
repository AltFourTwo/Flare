#pragma once

namespace Logging
{
   /***************************\
   \*****   ENUMERATORS   *****/
   enum LogLevel
   {
      TRACE = 1,
      DEBUG = 2,
      INFO = 3,
      WARNING = 4,
      ERR_OR = 5,
      FATAL = 6,
      OFF = 7
   };

   enum FormatControlCharacter
   {
      FCC_DATE = '%',
      FCC_LOGGER = '&'
   };

   // Control characters used by strftime in <ctime> (time.h)
   // www.cpluscplus.com/reference/ctime/strftime/
   //
   // Spanned as an enum for more user facing control.
   enum DateControlCharacter
   {
      DCC_ABBREVIATED_WEEKDAY_NAME = 'a',                                            //  %a  // Abbreviated weekday name *
      DCC_FULL_WEEKDAY_NAME = 'A',                                                   //  %A  // Full weekday name *
      DCC_ABBREVIATED_MONTH_NAME = 'b',                                              //  %b  // Abbreviated month name *
      DCC_FULL_MONTH_NAME = 'B',                                                     //  %B  // Full month name *
      DCC_DATE_AND_TIME_REPRESENTATION = 'c',                                        //  %c  // Date and time representation *
      DCC_YEAR_DIVIDED_BY_100_AND_TRUNCATED_TO_INTEGER = 'C',                        //  %C  // Year divided by 100 and truncated to integer( 00 - 99 )
      DCC_DAY_OF_THE_MONTH_ZERO_PADDED = 'd',                                        //  %d  // Day of the month, zero - padded( 01 - 31 )
      DCC_SHORT_MM_DD_YY_DATE = 'D',                                                 //  %D  // Short MM / DD / YY date, equivalent to %m / %d / %y
      DCC_DAY_OF_THE_MONTH_SPACE_PADDED = 'e',                                       //  %e  // Day of the month, space - padded( 1 - 31 )
      DCC_SHORT_YYYY_MM_DD_DATE = 'F',                                               //  %F  // Short YYYY - MM - DD date, equivalent to %Y - %m - %d
      DCC_WEEK_BASED_YEAR_LAST_TWO_DIGITS = 'g',                                     //  %g  // Week - based year, last two digits( 00 - 99 )
      DCC_WEEK_BASED_YEAR = 'G',                                                     //  %G  // Week - based year
      DCC_ABBREVIATED_MONTH_NAME_2 = 'h',                                            //  %h  // Abbreviated month name * ( same as %b )
      DCC_HOUR_IN_24H_FORMAT = 'H',                                                  //  %H  // Hour in 24h format( 00 - 23 )
      DCC_HOUR_IN_12H_FORMAT = 'I',                                                  //  %I  // Hour in 12h format( 01 - 12 )
      DCC_DAY_OF_THE_YEAR = 'j',                                                     //  %j  // Day of the year( 001 - 366 )
      DCC_MONTH_AS_A_DECIMAL_NUMBER = 'm',                                           //  %m  // Month as a decimal number( 01 - 12 )
      DCC_MINUTE = 'M',                                                              //  %M  // Minute( 00 - 59 )
      DCC_NEW_LINE_CHARACTER = 'n',                                                  //  %n  // New - line character( '\n' )
      DCC_AM_OR_PM_DESIGNATION = 'p',                                                //  %p  // AM or PM designation
      DCC_HOUR_CLOCK_TIME_12 = 'r',                                                  //  %r  // 12 - hour clock time *
      DCC_HOUR_CLOCK_TIME_24 = 'R',                                                  //  %R  // 24 - hour HH : MM time, equivalent to %H : %M
      DCC_SECOND = 'S',                                                              //  %S  // Second( 00 - 61 )
      DCC_HORIZONTAL_TAB_CHARACTER = 't',                                            //  %t  // Horizontal - tab character( '\t' )
      DCC_ISO_8601_TIME_FORMAT = 'T',                                                //  %T  // ISO 8601 time format( HH : MM : SS ), equivalent to %H : %M : %S
      DCC_ISO_8601_WEEKDAY_AS_NUMBER_WITH_MONDAY_AS_1 = 'u',                         //  %u  // ISO 8601 weekday as number with Monday as 1 ( 1 - 7 )
      DCC_WEEK_NUMBER_WITH_THE_FIRST_SUNDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE = 'U',      //  %U  // Week number with the first Sunday as the first day of week one( 00 - 53 )
      DCC_ISO_8601_WEEK_NUMBER = 'V',                                                //  %V  // ISO 8601 week number( 01 - 53 )
      DCC_WEEKDAY_AS_A_DECIMAL_NUMBER_WITH_SUNDAY_AS_0 = 'w',                        //  %w  // Weekday as a decimal number with Sunday as 0 ( 0 - 6 )
      DCC_WEEK_NUMBER_WITH_THE_FIRST_MONDAY_AS_THE_FIRST_DAY_OF_WEEK_ONE = 'W',      //  %W  // Week number with the first Monday as the first day of week one( 00 - 53 )
      DCC_DATE_REPRESENTATION = 'x',                                                 //  %x  // Date representation *
      DCC_TIME_REPRESENTATION = 'X',                                                 //  %X  // Time representation *
      DCC_YEAR_LAST_TWO_DIGITS = 'y',                                                //  %y  // Year, last two digits( 00 - 99 )
      DCC_YEAR = 'Y',                                                                //  %Y  // Year
      DCC_ISO_8601_OFFSET_FROM_UTC_IN_TIMEZONE = 'z',                                //  %z  // ISO 8601 offset from UTC in timezone( 1 minute = 1, 1 hour = 100 ) If timezone cannot be determined, no characters
      DCC_TIMEZONE_NAME_OR_ABBREVIATION = 'Z',                                       //  %Z  // Timezone name or abbreviation * If timezone cannot be determined, no characters
      DCC_A_PERCENTAGE_SIGN = '%'                                                    //  %%  // A % sign
   };

   // TODO Implement Thread ID and Process ID in logging.
   enum LoggingControlCharacter
   {
      LCC_MESSAGE = 'M',         // The actual message to log.
      LCC_LOG_LEVEL = 'L',       // The log level the message is issued as.
      LCC_LOGGER_NAME = 'N',     // The logger that is used to log the message.
      LCC_AMPERSAND = '&',       // The ampersand symbol '&'.
      LCC_SECONDS = 's',         // The number of seconds since the last message from this logger. 
      LCC_MILLISECONDS = 'm',    // The number of milliseconds since the last message from this logger.
      LCC_MICROSECONDS = 'u',    // The number of microseconds since the last message from this logger.
      LCC_NANOSECONDS = 'n',     // The number of nanoseconds since the last message from this logger.
      LCC_THREAD_ID = 't',       // The thread ID used by ? Where ? Leaving unimplemented for now.
      LCC_PROCESS_ID = 'p'       // The process ID used by ? Where ? Leaving unimplemented for now.
   };

   bool IsDateControlCharacter( const char a_Char );
   bool IsLoggingControlCharacter( const char a_Char );
}