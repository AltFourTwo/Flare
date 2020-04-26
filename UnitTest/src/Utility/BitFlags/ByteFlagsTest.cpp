#include "gtest/gtest.h"

#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::ByteFlags
{
   TEST( ByteFlagsTest, DefaultConstructor )
   {
      BitFlags::SingleByteFlags x_Flags;

      EXPECT_EQ(0, x_Flags.Value());
   }
}
