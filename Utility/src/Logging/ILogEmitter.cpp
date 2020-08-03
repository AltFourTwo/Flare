#include "UtilityPCH.h"

#include "ILogEmitter.h"

#include "Logging/Console.h"

namespace Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   ILogEmitter::ILogEmitter( const LoggerParameters& a_Parameters ) noexcept
   {
      m_Logger = Console::Instance().CreateLogger( a_Parameters );
   }

   ILogEmitter::ILogEmitter( LoggerParameters&& a_Parameters ) noexcept
   {
      m_Logger = Console::Instance().CreateLogger( std::move(a_Parameters) );
   }

   ILogEmitter::ILogEmitter( const ILogEmitter& a_Other ) noexcept
   {
      m_Logger = a_Other.m_Logger;
   }
}