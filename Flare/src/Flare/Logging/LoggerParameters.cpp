#include "FlarePCH.h"
#include "LoggerParameters.h"

namespace Flare::Logging
{
   /*****   ClASS   CONSTANTS    *****/
   const char* LoggerParameters::DEFAULT_LOGGER_NAME = "Unnamed Logger";
   const char* LoggerParameters::DEFAULT_FORMAT = "&M";

   /*****   CLASS CONSTRUCTORS   *****/
   LoggerParameters::LoggerParameters( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const char* a_FormatString, const int& a_TextColor, const int& a_BackgroundColor ) :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( a_FormatString ),
      m_TextColor( a_TextColor ),
      m_BackgroundColor( a_BackgroundColor )
   {}

   LoggerParameters::LoggerParameters( const LoggerParameters& a_Other ) :
      m_LoggerName( a_Other.m_LoggerName ),
      m_BaseLoggingLevel( a_Other.m_BaseLoggingLevel ),
      m_FormatString( a_Other.m_FormatString ),
      m_TextColor( a_Other.m_TextColor ),
      m_BackgroundColor( a_Other.m_BackgroundColor )
   {}

   LoggerParameters::LoggerParameters( LoggerParameters&& a_Other ) noexcept :
      m_LoggerName( a_Other.m_LoggerName ),
      m_BaseLoggingLevel( a_Other.m_BaseLoggingLevel ),
      m_FormatString( a_Other.m_FormatString ),
      m_TextColor( a_Other.m_TextColor ),
      m_BackgroundColor( a_Other.m_BackgroundColor )
   {
      a_Other.m_LoggerName = nullptr;
      a_Other.m_FormatString = nullptr;
   }

   /*****   CLASS   OPERATORS    *****/
   LoggerParameters& LoggerParameters::operator=( LoggerParameters&& a_Other ) noexcept
   {
      if ( this != &a_Other )
      {
         m_LoggerName = a_Other.m_LoggerName;
         m_FormatString = a_Other.m_FormatString;
         m_BaseLoggingLevel = a_Other.m_BaseLoggingLevel;
         m_TextColor = a_Other.m_TextColor;
         m_BackgroundColor = a_Other.m_BackgroundColor;

         a_Other.m_LoggerName = nullptr;
         a_Other.m_FormatString = nullptr;
      }

      return *this;
   };
}