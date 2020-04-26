#include "gtest/gtest.h"

#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::BitFlags::SingleByteFlags
{
   using SingleByteFlags = ::Utility::BitFlags::SingleByteFlags;

   class SingleByteFlagsTest : public ::testing::Test
   {
      protected:
      SingleByteFlags x_Flags;

      void SetUp() override {

      }
   };


   TEST_F(SingleByteFlagsTest, DefaultConstructor )
   {
      SingleByteFlags x_Flags;

      EXPECT_EQ(0, x_Flags.Value());
   }
}
