#include "gtest/gtest.h"

#include "BitFlags/BitMasks.h"
#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::BitFlags::SingleByteFlags
{
   namespace Masks = ::Utility::BitFlags::BitMasks;
   using SingleByteFlags = ::Utility::BitFlags::SingleByteFlags;

   TEST( SingleByteFlagsTest, DefaultConstructorAndValue )
   {
      SingleByteFlags x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, InitializeValueConstructor )
   {
      SingleByteFlags x_Flags( Masks::BIT03 );
      EXPECT_EQ( Masks::BIT03, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, SetAll )
   {
      SingleByteFlags x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT8_MAX, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, SetIndividually )
   {
      SingleByteFlags x_Flags;
      x_Flags.Set( 5 );
      EXPECT_EQ( Masks::BIT05, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, SetWithTrue )
   {
      SingleByteFlags x_Flags;
      x_Flags.Set( 4, true );
      EXPECT_EQ( Masks::BIT04, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, SetWithFalse )
   {
      uint8_t x_ExpectedValue = 0xEF;
      SingleByteFlags x_Flags( 0xFF );
      x_Flags.Set( 4, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, ResetAll )
   {
      SingleByteFlags x_Flags( 0xFF );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, ResetIndividually )
   {
      uint8_t x_ExpectedValue = 0x7F;
      SingleByteFlags x_Flags( 0xFF );
      x_Flags.Reset( 7 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, FlipAll )
   {
      uint8_t x_ExpectedValue = 0xAA;
      SingleByteFlags x_Flags( 0x55 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, FlipIndividual )
   {
      uint8_t x_ExpectedValue1 = 0xA8;
      uint8_t x_ExpectedValue2 = 0xAA;
      SingleByteFlags x_Flags( 0xAA );
      x_Flags.Flip( 1 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 1 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( SingleByteFlagsTest, AreAllOn )
   {
      SingleByteFlags x_Flags( 0xFF );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( SingleByteFlagsTest, AreAllOff )
   {
      SingleByteFlags x_Flags( 0 );
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 5 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( SingleByteFlagsTest, AnyOn )
   {
      SingleByteFlags x_Flags( 0xFF );
      EXPECT_TRUE(x_Flags.AnyOn());
      x_Flags.Reset( 4 );
      EXPECT_TRUE(x_Flags.AnyOn());
      x_Flags.Reset();
      EXPECT_FALSE(x_Flags.AnyOn());
   }

   TEST( SingleByteFlagsTest, ValueIndividual )
   {
      SingleByteFlags x_Flags( 0 );
      EXPECT_FALSE( x_Flags.Value( 5 ) );
      x_Flags.Set( 5 );
      EXPECT_TRUE( x_Flags.Value( 5 ) );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.Value( 5 ) );
   }
}
