#include "gtest/gtest.h"

#include "BitFlags/BitMasks.h"
#include "BitFlags/BitFlags.h"

namespace UnitTest::Utility::BitFlags::OctaByteFlags
{
   namespace Masks = ::Utility::BitFlags::BitMasks;
   using OctaByteFlags = ::Utility::BitFlags::OctaByteFlags;

   TEST( OctaByteFlagsTest, DefaultConstructor )
   {
      OctaByteFlags x_Flags;
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, InitializeValueConstructor )
   {
      OctaByteFlags x_Flags( Masks::BIT43 );
      EXPECT_EQ( Masks::BIT43, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, SetAll )
   {
      OctaByteFlags x_Flags;
      x_Flags.Set();
      EXPECT_EQ( UINT64_MAX, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, SetIndividually )
   {
      OctaByteFlags x_Flags;
      x_Flags.Set( 45 );
      EXPECT_EQ( Masks::BIT45, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, SetWithTrue )
   {
      OctaByteFlags x_Flags;
      x_Flags.Set( 44, true );
      EXPECT_EQ( Masks::BIT44, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, SetWithFalse )
   {
      uint64_t x_ExpectedValue = 0xFFFF'EFFF'FFFF'FFFF;
      OctaByteFlags x_Flags( UINT64_MAX );
      x_Flags.Set( 44, false );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, ResetAll )
   {
      OctaByteFlags x_Flags( UINT64_MAX );
      x_Flags.Reset();
      EXPECT_EQ( 0, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, ResetIndividually )
   {
      uint64_t x_ExpectedValue = 0xFFFF'7FFF'FFFF'FFFF;
      OctaByteFlags x_Flags( UINT64_MAX );
      x_Flags.Reset( 47 );
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, FlipAll )
   {
      uint64_t x_ExpectedValue = 0xAAAA'AAAA'AAAA'AAAA;
      OctaByteFlags x_Flags( 0x5555'5555'5555'5555 );
      x_Flags.Flip();
      EXPECT_EQ( x_ExpectedValue, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, FlipIndividual )
   {
      uint64_t x_ExpectedValue1 = 0xAAAA'AAAA'AAAA'AAAA;
      uint64_t x_ExpectedValue2 = 0xAAA2'AAAA'AAAA'AAAA;
      OctaByteFlags x_Flags( 0xAAA2'AAAA'AAAA'AAAA );
      x_Flags.Flip( 51 );
      EXPECT_EQ( x_ExpectedValue1, x_Flags.Value() );
      x_Flags.Flip( 51 );
      EXPECT_EQ( x_ExpectedValue2, x_Flags.Value() );
   }

   TEST( OctaByteFlagsTest, AreAllOn )
   {
      OctaByteFlags x_Flags( UINT64_MAX );
      EXPECT_TRUE( x_Flags.AreAllOn() );
      x_Flags.Reset( 5 );
      EXPECT_FALSE( x_Flags.AreAllOn() );
   }

   TEST( OctaByteFlagsTest, AreAllOff )
   {
      OctaByteFlags x_Flags( 0 );
      EXPECT_TRUE( x_Flags.AreAllOff() );
      x_Flags.Set( 5 );
      EXPECT_FALSE( x_Flags.AreAllOff() );
   }

   TEST( OctaByteFlagsTest, AnyOn )
   {
      OctaByteFlags x_Flags( 0xFFFF'FFFF'FFFF'FFFF );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset( 42 );
      EXPECT_TRUE( x_Flags.AnyOn() );
      x_Flags.Reset();
      EXPECT_FALSE( x_Flags.AnyOn() );
   }

   TEST( OctaByteFlagsTest, ValueIndividual )
   {
      OctaByteFlags x_Flags( 0 );
      EXPECT_FALSE( x_Flags.Value( 55 ) );
      x_Flags.Set( 55 );
      EXPECT_TRUE( x_Flags.Value( 55 ) );
      x_Flags.Reset( 55 );
      EXPECT_FALSE( x_Flags.Value( 55 ) );
   }
}
