#include "gtest/gtest.h"

#include "BitFlags/BitMasks.h"
#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::BitFlags::QuadByteFlags
{
   namespace Masks = ::Utility::BitFlags::BitMasks;
   using QuadByteFlags = ::Utility::BitFlags::QuadByteFlags;

   TEST( QuadByteFlagsTest, DefaultConstructorAndValue )
   {
      QuadByteFlags x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, InitializeValueConstructor )
   {
      QuadByteFlags x_Flags( Masks::S_BIT23 );
      EXPECT_EQ( Masks::S_BIT23, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, SetAll )
   {
      QuadByteFlags x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT32_MAX, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, SetIndividually )
   {
      QuadByteFlags x_Flags;
      x_Flags.Set( 25 );
      EXPECT_EQ( Masks::S_BIT25, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, SetWithTrue )
   {
      QuadByteFlags x_Flags;
      x_Flags.Set( 24, true );
      EXPECT_EQ( Masks::S_BIT24, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, SetWithFalse )
   {
      uint64_t x_ExpectedValue = 0xFEFF'FFFF;
      QuadByteFlags x_Flags( UINT32_MAX );
      x_Flags.Set( 24, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, ResetAll )
   {
      QuadByteFlags x_Flags( UINT32_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, ResetIndividually )
   {
      uint64_t x_ExpectedValue = 0xFFFD'FFFF;
      QuadByteFlags x_Flags( UINT32_MAX );
      x_Flags.Reset( 17 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, FlipAll )
   {
      uint64_t x_ExpectedValue = 0xAAAA'AAAA;
      QuadByteFlags x_Flags( 0x5555'5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, FlipIndividual )
   {

      uint64_t x_ExpectedValue1 = 0xA2AA'AAAA;
      uint64_t x_ExpectedValue2 = 0xAAAA'AAAA;
      QuadByteFlags x_Flags( 0xAAAA'AAAA );
      x_Flags.Flip( 27 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 27 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( QuadByteFlagsTest, AreAllOn )
   {
      QuadByteFlags x_Flags( UINT32_MAX );
      EXPECT_EQ( true, x_Flags.AreAllOn() );
      x_Flags.Reset( 26 );
      EXPECT_EQ( false, x_Flags.AreAllOn() );
   }

   TEST( QuadByteFlagsTest, AreAllOff )
   {
      QuadByteFlags x_Flags( 0 );
      EXPECT_EQ( true, x_Flags.AreAllOff() );
      x_Flags.Set( 26 );
      EXPECT_EQ( false, x_Flags.AreAllOff() );
   }

   TEST( QuadByteFlagsTest, ValueIndividual )
   {
      QuadByteFlags x_Flags( 0 );
      EXPECT_EQ( false, x_Flags.Value( 30 ) );
      x_Flags.Set( 30 );
      EXPECT_EQ( true, x_Flags.Value( 30 ) );
      x_Flags.Reset( 30 );
      EXPECT_EQ( false, x_Flags.Value( 30 ) );
   }
}
