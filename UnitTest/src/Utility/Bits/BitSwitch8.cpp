#include "gtest/gtest.h"

#include "Bits/Masks.h"
#include "Bits/BitSwitch.h"

namespace UnitTest::Utility::Bits::BitSwitch8
{
   namespace Masks = ::Utility::Bits::Masks;
   using BitSwitch8 = ::Utility::Bits::BitSwitch8;

   TEST( BitSwitch8_Test, DefaultConstructorAndValue )
   {
      BitSwitch8 x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, InitializeValueConstructor )
   {
      BitSwitch8 x_Flags( Masks::BIT03 );
      EXPECT_EQ( Masks::BIT03, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, SetAll )
   {
      BitSwitch8 x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT8_MAX, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, SetIndividually )
   {
      BitSwitch8 x_Flags;
      x_Flags.Set( 5 );
      EXPECT_EQ( Masks::BIT05, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, SetWithTrue )
   {
      BitSwitch8 x_Flags;
      x_Flags.Set( 4, true );
      EXPECT_EQ( Masks::BIT04, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, SetWithFalse )
   {
      uint8_t x_ExpectedValue = 0xEF;
      BitSwitch8 x_Flags( 0xFF );
      x_Flags.Set( 4, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, ResetAll )
   {
      BitSwitch8 x_Flags( 0xFF );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, ResetIndividually )
   {
      uint8_t x_ExpectedValue = 0x7F;
      BitSwitch8 x_Flags( 0xFF );
      x_Flags.Reset( 7 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, FlipAll )
   {
      uint8_t x_ExpectedValue = 0xAA;
      BitSwitch8 x_Flags( 0x55 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, FlipIndividual )
   {
      uint8_t x_ExpectedValue1 = 0xA8;
      uint8_t x_ExpectedValue2 = 0xAA;
      BitSwitch8 x_Flags( 0xAA );
      x_Flags.Flip( 1 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 1 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( BitSwitch8_Test, AreAllOn )
   {
      BitSwitch8 x_Flags( 0xFF );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( BitSwitch8_Test, AreAllOff )
   {
      BitSwitch8 x_Flags( 0 );
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 5 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( BitSwitch8_Test, AnyOn )
   {
      BitSwitch8 x_Flags( 0xFF );
      EXPECT_TRUE(x_Flags.AnyOn());
      x_Flags.Reset( 4 );
      EXPECT_TRUE(x_Flags.AnyOn());
      x_Flags.Reset();
      EXPECT_FALSE(x_Flags.AnyOn());
   }

   TEST( BitSwitch8_Test, ValueIndividual )
   {
      BitSwitch8 x_Flags( 0 );
      EXPECT_FALSE( x_Flags.Value( 5 ) );
      x_Flags.Set( 5 );
      EXPECT_TRUE( x_Flags.Value( 5 ) );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.Value( 5 ) );
   }
}
