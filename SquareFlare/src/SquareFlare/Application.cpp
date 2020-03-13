#include "SquareFlarePCH.h"

#include "Application.h"
#include "Test/TestObject.h"
#include "Composing/Composition.h"
#include "Logging/Console.h"

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

      Logging::Console& console = Logging::Console::Get();
      Logging::Logger help = console.Initialize( "Console", Logging::LogLevel::INFO, 1, 1, "[%R][&N][&L] &M && %% &^ \n" );

      printf( "\n" );
      help.Trace( "TraceMsg" );
      help.Debug( "DebugMsg" );
      help.Info( "InfoMsg" );
      help.Warn( "WarnMsg" );
      help.Error( "ErrorMsg" );
      help.Fatal( "FatalMsg" );
   }
}
