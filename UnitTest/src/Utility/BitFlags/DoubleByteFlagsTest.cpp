#include "gtest/gtest.h"

#include "BitFlags/BitMasks.h"
#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::BitFlags::DoubleByteFlags
{
   namespace Masks = ::Utility::BitFlags::BitMasks;
   using DoubleByteFlags = ::Utility::BitFlags::DoubleByteFlags;

   TEST( DoubleByteFlagsTest, DefaultConstructor )
   {
      DoubleByteFlags x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, InitializeValueConstructor )
   {
      DoubleByteFlags x_Flags( Masks::S_BIT03 );
      EXPECT_EQ( Masks::S_BIT03, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, SetAll )
   {
      DoubleByteFlags x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT16_MAX, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, SetIndividually )
   {
      DoubleByteFlags x_Flags;
      x_Flags.Set( 15 );
      EXPECT_EQ( Masks::S_BIT15, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, SetWithTrue )
   {
      DoubleByteFlags x_Flags;
      x_Flags.Set( 14, true );
      EXPECT_EQ( Masks::S_BIT14, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, SetWithFalse )
   {
      uint16_t x_ExpectedValue = 0xBFFF;
      DoubleByteFlags x_Flags( UINT16_MAX );
      x_Flags.Set( 14, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, ResetAll )
   {
      DoubleByteFlags x_Flags( UINT16_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, ResetIndividually )
   {
      uint16_t x_ExpectedValue = 0xF7FF;
      DoubleByteFlags x_Flags( UINT16_MAX );
      x_Flags.Reset( 11 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, FlipAll )
   {
      uint16_t x_ExpectedValue = 0xAAAA;
      DoubleByteFlags x_Flags( 0x5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, FlipIndividual )
   {
      uint16_t x_ExpectedValue1 = 0xA8FF;
      uint16_t x_ExpectedValue2 = 0xAAFF;
      DoubleByteFlags x_Flags( 0xAAFF );
      x_Flags.Flip( 9 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 9 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( DoubleByteFlagsTest, AreAllOn )
   {
      DoubleByteFlags x_Flags( UINT16_MAX );
      EXPECT_EQ( true, x_Flags.AreAllOn() );
      x_Flags.Reset( 13 );
      EXPECT_EQ( false, x_Flags.AreAllOn() );
   }

   TEST( DoubleByteFlagsTest, AreAllOff )
   {
      DoubleByteFlags x_Flags;
      EXPECT_EQ( true, x_Flags.AreAllOff() );
      x_Flags.Set( 13 );
      EXPECT_EQ( false, x_Flags.AreAllOff() );
   }

   TEST( DoubleByteFlagsTest, ValueIndividual )
   {
      DoubleByteFlags x_Flags;
      EXPECT_EQ( false, x_Flags.Value( 12 ) );
      x_Flags.Set( 12 );
      EXPECT_EQ( true, x_Flags.Value( 12 ) );
      x_Flags.Reset( 12 );
      EXPECT_EQ( false, x_Flags.Value( 12 ) );
   }
}
