#include "FlarePCH.h"
#include "LogService.h"

#include "Flare/Core/Core.h"
#include "Flare/Logging/Logging.h"

namespace Flare::Logging
{
   /*****   VARIABLES   *****/
   LogService* LogService::s_Instance = nullptr;

   /*****  C-TOR D-TOR  *****/
   LogService::LogService() noexcept :
      m_Loggers(),
      m_Sinks(),
      m_Buckets(),
      m_CoreLogger( nullptr ),
      m_ClientLogger( nullptr ),
      m_Running( false )
   {}

   LogService::~LogService() noexcept
   {
      m_Running = false;
      m_Loggers.clear();
      m_Buckets.clear();
      m_Sinks.clear();
   }

   /*****   FUNCTIONS   *****/
   LogService& LogService::Initialize()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::LogService aleady exists!" ); // TODO more logs & error codes.
      s_Instance = new LogService();
      s_Instance->InitInstance();
      return *s_Instance;
   }

   void LogService::Start()
   {
      s_Instance->m_Running = true;
   }

   void LogService::Stop()
   {
      s_Instance->m_Running = false;
   }

   void LogService::InitInstance()
   {
      m_Loggers.reserve( 2 );

      m_CoreLogger = m_Loggers.emplace_back( Logger::Create( "Core" ) );
      m_CoreLogger->SetLoggingLevel( LogLevel::Trace );
      m_CoreLogger->SetFormatString( "[{0:T%H:%M}] {0:N} : {0:M}\n" );

      m_ClientLogger = m_Loggers.emplace_back( Logger::Create( "Client" ) );
      m_ClientLogger->SetLoggingLevel( LogLevel::Trace );
      m_ClientLogger->SetFormatString( "[{0:T%H:%M}] ({0:P}) {0:N} : {0:M}\n" );
   }

   // Logger Managing.

   SharedLogger LogService::CreateLogger( const char* a_LoggerName )
   {
      SharedLogger x_NewLogger = m_Loggers.emplace_back( Logger::Create( a_LoggerName ) );
      return x_NewLogger;
   }

   SharedLogger LogService::CreateLogger( std::string&& a_LoggerName )
   {
      SharedLogger x_NewLogger = m_Loggers.emplace_back( Logger::Create( std::move( a_LoggerName ) ) );
      return x_NewLogger;
   }

   void LogService::StartLoggers()
   {
      for ( SharedLogger x_Logger : m_Loggers )
         x_Logger->Enable();
   }

   void LogService::StopLoggers()
   {
      for ( SharedLogger x_Logger : m_Loggers )
         x_Logger->Disable();
   }

   // Sinks Managing.
   SharedSink LogService::CreateSink( std::string&& a_SinkName )
   {
      SharedSink x_NewSink = s_Instance->m_Sinks.emplace_back( Sink::Create() );
      return x_NewSink;
   }

   void LogService::OpenSinks()
   {
      for ( SharedSink x_Sink : m_Sinks )
         x_Sink->Open();
   }

   void LogService::CloseSinks()
   {
      for ( SharedSink x_Sink : m_Sinks )
         x_Sink->Close();
   }

   // Buckets Managing.
   SharedBucket LogService::CreateBucket( std::string&& a_BucketName )
   {
      SharedBucket x_NewBucket = s_Instance->m_Buckets.emplace_back( Bucket::Create() );
      return x_NewBucket;
   }

   void LogService::OpenBuckets()
   {
      for ( SharedBucket x_Bucket : m_Buckets )
         x_Bucket->Open();
   }

   void LogService::CloseBuckets()
   {
      for ( SharedBucket x_Bucket : m_Buckets )
         x_Bucket->Close();
   }
}
