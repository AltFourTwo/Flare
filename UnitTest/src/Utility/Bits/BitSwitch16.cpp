#include "gtest/gtest.h"

#include "Bits/Masks.h"
#include "Bits/BitSwitch.h"

namespace UnitTest::Utility::Bits::BitSwitch16
{
   namespace Masks = ::Utility::Bits::Masks;
   using BitSwitch16 = ::Utility::Bits::BitSwitch16;

   TEST( BitSwitch16_Test, DefaultConstructor )
   {
      BitSwitch16 x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, InitializeValueConstructor )
   {
      BitSwitch16 x_Flags( Masks::BIT03 );
      EXPECT_EQ( Masks::BIT03, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, SetAll )
   {
      BitSwitch16 x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT16_MAX, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, SetIndividually )
   {
      BitSwitch16 x_Flags;
      x_Flags.Set( 15 );
      EXPECT_EQ( Masks::BIT15, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, SetWithTrue )
   {
      BitSwitch16 x_Flags;
      x_Flags.Set( 14, true );
      EXPECT_EQ( Masks::BIT14, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, SetWithFalse )
   {
      uint16_t x_ExpectedValue = 0xBFFF;
      BitSwitch16 x_Flags( UINT16_MAX );
      x_Flags.Set( 14, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, ResetAll )
   {
      BitSwitch16 x_Flags( UINT16_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, ResetIndividually )
   {
      uint16_t x_ExpectedValue = 0xF7FF;
      BitSwitch16 x_Flags( UINT16_MAX );
      x_Flags.Reset( 11 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, FlipAll )
   {
      uint16_t x_ExpectedValue = 0xAAAA;
      BitSwitch16 x_Flags( 0x5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, FlipIndividual )
   {
      uint16_t x_ExpectedValue1 = 0xA8FF;
      uint16_t x_ExpectedValue2 = 0xAAFF;
      BitSwitch16 x_Flags( 0xAAFF );
      x_Flags.Flip( 9 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 9 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( BitSwitch16_Test, AreAllOn )
   {
      BitSwitch16 x_Flags( UINT16_MAX );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 13 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( BitSwitch16_Test, AreAllOff )
   {
      BitSwitch16 x_Flags;
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 13 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( BitSwitch16_Test, AnyOn )
   {
      BitSwitch16 x_Flags( 0xFFFF );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset( 10 );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset();
      EXPECT_FALSE( x_Flags.AnyOn() );
   }

   TEST( BitSwitch16_Test, ValueIndividual )
   {
      BitSwitch16 x_Flags;
      EXPECT_FALSE( x_Flags.Value( 12 ) );
      x_Flags.Set( 12 );
      EXPECT_TRUE( x_Flags.Value( 12 ) );
      x_Flags.Reset( 12 );
      EXPECT_FALSE( x_Flags.Value( 12 ) );
   }
}
