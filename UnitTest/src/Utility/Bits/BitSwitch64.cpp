#include "gtest/gtest.h"

#include "Bits/Masks.h"
#include "Bits/BitSwitch.h"

namespace UnitTest::Utility::Bits::BitSwitch64
{
   namespace Masks = ::Utility::Bits::Masks;
   using BitSwitch64 = ::Utility::Bits::BitSwitch64;

   TEST( BitSwitch64_Test, DefaultConstructor )
   {
      BitSwitch64 x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, InitializeValueConstructor )
   {
      BitSwitch64 x_Flags( Masks::BIT43 );
      EXPECT_EQ( Masks::BIT43, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, SetAll )
   {
      BitSwitch64 x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT64_MAX, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, SetIndividually )
   {
      BitSwitch64 x_Flags;
      x_Flags.Set( 45 );
      EXPECT_EQ( Masks::BIT45, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, SetWithTrue )
   {
      BitSwitch64 x_Flags;
      x_Flags.Set( 44, true );
      EXPECT_EQ( Masks::BIT44, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, SetWithFalse )
   {
      uint64_t x_ExpectedValue = 0xFFFF'EFFF'FFFF'FFFF;
      BitSwitch64 x_Flags( UINT64_MAX );
      x_Flags.Set( 44, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, ResetAll )
   {
      BitSwitch64 x_Flags( UINT64_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, ResetIndividually )
   {
      uint64_t x_ExpectedValue = 0xFFFF'7FFF'FFFF'FFFF;
      BitSwitch64 x_Flags( UINT64_MAX );
      x_Flags.Reset( 47 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, FlipAll )
   {
      uint64_t x_ExpectedValue = 0xAAAA'AAAA'AAAA'AAAA;
      BitSwitch64 x_Flags( 0x5555'5555'5555'5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, FlipIndividual )
   {
      uint64_t x_ExpectedValue1 = 0xAAAA'AAAA'AAAA'AAAA;
      uint64_t x_ExpectedValue2 = 0xAAA2'AAAA'AAAA'AAAA;
      BitSwitch64 x_Flags( 0xAAA2'AAAA'AAAA'AAAA );
      x_Flags.Flip( 51 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 51 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( BitSwitch64_Test, AreAllOn )
   {
      BitSwitch64 x_Flags( UINT64_MAX );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( BitSwitch64_Test, AreAllOff )
   {
      BitSwitch64 x_Flags( 0 );
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 5 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( BitSwitch64_Test, AnyOn )
   {
      BitSwitch64 x_Flags( 0xFFFF'FFFF'FFFF'FFFF );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset( 42 );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset();
      EXPECT_FALSE( x_Flags.AnyOn() );
   }

   TEST( BitSwitch64_Test, ValueIndividual )
   {
      BitSwitch64 x_Flags( 0 );
      EXPECT_FALSE( x_Flags.Value( 55 ) );
      x_Flags.Set( 55 );
      EXPECT_TRUE( x_Flags.Value( 55 ) );
      x_Flags.Reset( 55 );
      EXPECT_FALSE( x_Flags.Value( 55 ) );
   }
}
