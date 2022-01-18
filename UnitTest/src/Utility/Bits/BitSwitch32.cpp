#include "gtest/gtest.h"

#include "Bits/Bits.h"
#include "Bits/BitSwitch.h"

namespace UnitTest::Utility::Bits::BitSwitch32
{
   namespace Bits = ::Utility::Bits;
   using BitSwitch32 = ::Utility::Bits::BitSwitch32;

   TEST( BitSwitch32_Test, DefaultConstructorAndValue )
   {
      BitSwitch32 x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, InitializeValueConstructor )
   {
      BitSwitch32 x_Flags( Bits::BIT23 );
      EXPECT_EQ( Bits::BIT23, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, SetAll )
   {
      BitSwitch32 x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT32_MAX, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, SetIndividually )
   {
      BitSwitch32 x_Flags;
      x_Flags.Set( 25 );
      EXPECT_EQ( Bits::BIT25, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, SetWithTrue )
   {
      BitSwitch32 x_Flags;
      x_Flags.Set( 24, true );
      EXPECT_EQ( Bits::BIT24, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, SetWithFalse )
   {
      uint64_t x_ExpectedValue = 0xFEFF'FFFF;
      BitSwitch32 x_Flags( UINT32_MAX );
      x_Flags.Set( 24, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, ResetAll )
   {
      BitSwitch32 x_Flags( UINT32_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, ResetIndividually )
   {
      uint64_t x_ExpectedValue = 0xFFFD'FFFF;
      BitSwitch32 x_Flags( UINT32_MAX );
      x_Flags.Reset( 17 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, FlipAll )
   {
      uint64_t x_ExpectedValue = 0xAAAA'AAAA;
      BitSwitch32 x_Flags( 0x5555'5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, FlipIndividual )
   {

      uint64_t x_ExpectedValue1 = 0xA2AA'AAAA;
      uint64_t x_ExpectedValue2 = 0xAAAA'AAAA;
      BitSwitch32 x_Flags( 0xAAAA'AAAA );
      x_Flags.Flip( 27 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 27 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( BitSwitch32_Test, AreAllOn )
   {
      BitSwitch32 x_Flags( UINT32_MAX );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 26 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( BitSwitch32_Test, AreAllOff )
   {
      BitSwitch32 x_Flags( 0 );
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 26 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( BitSwitch32_Test, AnyOn )
   {
      BitSwitch32 x_Flags( 0xFFFF'FFFF );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset( 19 );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset();
      EXPECT_FALSE( x_Flags.AnyOn() );
   }

   TEST( BitSwitch32_Test, ValueIndividual )
   {
      BitSwitch32 x_Flags( 0 );
      EXPECT_FALSE( x_Flags.Value( 30 ) );
      x_Flags.Set( 30 );
      EXPECT_TRUE( x_Flags.Value( 30 ) );
      x_Flags.Reset( 30 );
      EXPECT_FALSE( x_Flags.Value( 30 ) );
   }
}
