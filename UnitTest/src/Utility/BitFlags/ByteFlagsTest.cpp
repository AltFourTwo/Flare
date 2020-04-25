#include "UnitTestPCH.h"
#include "CppUnitTest.h"

#include "BitFlags/BitFlags.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
   TEST_CLASS( ByteFlags )
   {
      public:

      TEST_METHOD( GetBitMask )
      {
         int abc = 1;
         int cba = 1;

         Assert::AreEqual(abc, cba, L"Test ABC CBA");
      }
   };
}
