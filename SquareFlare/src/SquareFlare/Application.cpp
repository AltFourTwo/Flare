#include "SquareFlarePCH.h"

#include "Application.h"

// Temporary Includes
#include "Test/TestObject.h"
#include "Composing/Composition.h"
#include "Logging/Console.h"
#include "Exceptions/UtilityException.h"
#include "Events/Events.h"

#include <cstdint>

namespace SquareFlare
{
   Application::Application()
   {}

   Application::~Application()
   {}

   void Application::Run()
   {
      while ( true );
   }

   void Application::Test()
   {
      std::cout << std::endl;

      /*
      TestObject hi;
      hi.x = 5;
      hi.y = 10;

      int y = 2;
      int z = 4;
      int az = 4;
      int pbg = 6;
      int oup = 1234567890;
      bool booltrue = true;
      bool boolfalse = false;
      char somechar = '*';

      std::cout << Composing::Format( "This is a message from : {0}.", { hi } ).c_str() << "\n";
      std::cout << Composing::Format( "This is a message from : {0,-1}.", { hi } ).c_str() << "\n";
      std::cout << Composing::Format( "This is a message from : {0:'{'format'}'}.", { hi } ).c_str() << "\n";
      std::cout << Composing::Format( "This is a message from : {0:'{'format'}',-15}.", { hi } ).c_str() << "\n";
      std::cout << Composing::Format( "This is a message from : {0,15:'{'format'}'}.", { hi } ).c_str() << "\n";
      std::cout << Composing::Format( "This is a message from : {0,15:'{'format'}'} and {1,15:X}.", { hi, hi } ).c_str() << "\n";
      std::cout << Composing::Format( "Maybe {0,10:'[ 'hey' , 'there' ]'},{1},{2},{3}.", { y, z, az, pbg } ).c_str() << "\n";
      std::cout << Composing::Format( "Try to format this -> {0,15:B36P10}.", { oup } ) << "\n";
      std::cout << Composing::Format( "Try to format this -> {0:X}.", { oup } ) << "\n";
      std::cout << std::to_string( true ) << "\n";
      std::cout << std::to_string( false ) << "\n";

      std::cout << "True..." << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0}.", { booltrue } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:text-t/f}.", { booltrue } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:text-y/n}.", { booltrue } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:T/F}.", { booltrue } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:Y/N}.", { booltrue } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:O/X}.", { booltrue } ) << "\n\n";

      std::cout << "False..." << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0}.", { boolfalse } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:text-t/f}.", { boolfalse } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:text-y/n}.", { boolfalse } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:T/F}.", { boolfalse } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:Y/N}.", { boolfalse } ) << "\n";
      std::cout << Composing::Format( "Try to format this bool -> {0:O/X}.", { boolfalse } ) << "\n\n";

      std::cout << "Char..." << "\n";
      std::cout << Composing::Format( "Try to format this char -> {0}.", { somechar } ) << "\n";
      std::cout << Composing::Format( "Try to format this char -> {0:#}.", { somechar } ) << "\n";
      std::cout << Composing::Format( "Try to format this char -> {0:DummyFormatReturnsTheChar}.", { somechar } ) << "\n";
      */

      /*
      Logging::Console& console = Logging::Console::Get();
      Logging::Logger x_Test = console.Initialize( "Console", Logging::LogLevel::INFO, 1, 1, "[%R][&N][&L] &M && %% &^ \n" );

      printf( "\n" );
      x_Test.Trace( "TraceMsg" );
      x_Test.Debug( "DebugMsg" );
      x_Test.Info( "InfoMsg" );
      x_Test.Warn( "WarnMsg" );
      x_Test.Error( "ErrorMsg" );
      x_Test.Fatal( "FatalMsg" );

      Logging::Logger x_TimeDiffLog = console.CreaterLogger("TimeDiffTest", Logging::LogLevel::TRACE, 1, 1, "[&N] Testing Time Control Characters\n - Seconds &s\n - Milliseconds &m\n - Microseconds &u\n - Nanoseconds &n\n&M Done.\n" );
      
      x_TimeDiffLog.Trace("Test 1");
      x_TimeDiffLog.Trace("Test 2");
      x_TimeDiffLog.Trace("Test 3");
      x_TimeDiffLog.Trace("Test 4");
      x_TimeDiffLog.Trace("Test 5");

      x_TimeDiffLog.SetFormat( "[&N] Testing Smart Time Control Option\n - Smart &t\n&M Done.\n" );

      using namespace std::literals::chrono_literals;

      x_TimeDiffLog.Trace( "Test Smart Begin" );

      std::this_thread::sleep_for( 150us );
      x_TimeDiffLog.Trace( "Test Smart > Microseconds" );

      std::this_thread::sleep_for( 150ms );
      x_TimeDiffLog.Trace( "Test Smart > Milliseconds" );

      std::this_thread::sleep_for( 2s );
      x_TimeDiffLog.Trace( "Test Smart > Seconds" );
      */

      /*
      try
      {
         std::cout << Composing::Format( "Fail at this {5}.", { 1 } ) << "\n";
      }
      catch ( Utility::Exceptions::UtilityException& e )
      {
         std::cout << e.what() << "\n";
      }
      */

      /*
      uint8_t integer8 = 0xF4;
      uint64_t integer64 = 0xFFFF'0104'0280'00F4;
      std::cout << (integer8 & integer64) << std::endl;
      */

      SquareFlare::Events::MouseButtonPressedEvent x_LMBclick = SquareFlare::Events::MouseButtonPressedEvent(1);
      std::cout << x_LMBclick << std::endl;
   }
}
