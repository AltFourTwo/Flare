#pragma once

#include "Flare/Logging/Bucket.h"
#include "Flare/Logging/Logger.h"
#include "Flare/Logging/Sink.h"

#include "Flare/Logging/Logging.h"

#include "Flare/Core/Collection.h"

namespace Flare::Logging
{
   class LogService
   {
      /*****   VARIABLES   *****/
      private:
      static LogService* s_Instance;
      SharedLogger m_CoreLogger;
      SharedLogger m_ClientLogger;
      std::vector<SharedBucket> m_Buckets;
      std::vector<SharedLogger> m_Loggers;
      std::vector<SharedSink> m_Sinks;
      std::unordered_map<std::string, int> m_NamesMap;
      bool m_Running;

      /*****   C-TOR D-TOR   *****/
      private:
      LogService() noexcept;
      ~LogService() noexcept;

      public:
      LogService( const LogService& a_Other ) = delete;

      /*****   FUNCTIONS   *****/
      public:
      static LogService& Initialize( /* TODO Config */ );
      static void Start();
      static void Stop();
      void InitInstance();

      SharedLogger CreateLogger( const char* a_LoggerName );
      SharedLogger CreateLogger( std::string&& a_LoggerName );
      void StartLoggers();
      void StopLoggers();

      SharedSink CreateSink( std::string&& a_SinkName );
      void OpenSinks();
      void CloseSinks();

      SharedBucket CreateBucket( std::string&& a_BucketName );
      void OpenBuckets();
      void CloseBuckets();

      /*****   OPERATORS    *****/
      public:
      void operator=( const LogService& ) = delete;

      /*****   GETTERS   *****/
      public:
      inline static LogService& GetInstance() { return *s_Instance; }
      inline static SharedLogger GetCoreLogger() { return s_Instance->m_CoreLogger; }
      inline static SharedLogger GetClientLogger() { return s_Instance->m_ClientLogger; }

      /*****   PROPERTIES   *****/
      public:
      Collection<std::vector<SharedSink>> Sinks = Collection(m_Sinks);
   };
}
