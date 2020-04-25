#include "UnitTestPCH.h"
#include "CppUnitTest.h"
#include "BitFlags/BitFlags.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest::Utility::ByteFlags
{
   TEST_CLASS( ByteFlagsTest )
   {
      public:
      TEST_METHOD( ByteFlagsDefaultConstructor )
      {
         BitFlags::SingleByteFlags x_Flags;

         Assert::AreEqual( 0ui8, x_Flags.Value() );
      }
   };
}
