#pragma once

#include <cstdint>

namespace Utility::Bits
{
   template<typename T>
   class BitSwitch
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      T m_Flags;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      BitSwitch();
      BitSwitch( T a_IntegralValue );

      /*****   CLASS   FUNCTIONS    *****/
      private:
      static T GetBitMask( const uint8_t& a_Pos );

      public:
      void Set();
      void Set( const uint8_t& a_Pos );
      void Set( const uint8_t& a_Pos, const bool& a_Value );
      void Reset();
      void Reset( const uint8_t& a_Pos );
      void Flip();
      void Flip( const uint8_t& a_Pos );
      bool AreAllOn();
      bool AreAllOff();
      bool AnyOn();
      const T& Value();
      const bool Value( const uint8_t& a_Pos );
   };

   class BitSwitch8 : public BitSwitch<uint8_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      BitSwitch8() : BitSwitch() {}
      BitSwitch8( const uint8_t& a_IntegralValue ) : BitSwitch( a_IntegralValue ) {}
   };

   class BitSwitch16 : public BitSwitch<uint16_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      BitSwitch16() : BitSwitch() {}
      BitSwitch16( const uint16_t& a_IntegralValue ) : BitSwitch( a_IntegralValue ) {}
   };

   class BitSwitch32 : public BitSwitch<uint32_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      BitSwitch32() : BitSwitch() {}
      BitSwitch32( const uint32_t& a_IntegralValue ) : BitSwitch( a_IntegralValue ) {}
   };

   class BitSwitch64 : public BitSwitch<uint64_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      BitSwitch64() : BitSwitch() {}
      BitSwitch64( const uint64_t& a_IntegralValue ) : BitSwitch( a_IntegralValue ) {}
   };

   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   BitSwitch<T>::BitSwitch() :
      m_Flags( 0 )
   {}

   template<typename T>
   BitSwitch<T>::BitSwitch( T a_IntegralValue ) :
      m_Flags( a_IntegralValue )
   {}

   /*****   CLASS   FUNCTIONS    *****/
   template<typename T>
   T BitSwitch<T>::GetBitMask( const uint8_t& a_Pos )
   {
      T x_Mask = 1;
      x_Mask <<= a_Pos;

      if ( !x_Mask )
         return x_Mask;
         // TODO Log a warning when result mask is 0. (Left shift overflow.)

      return x_Mask;
   }

   template<typename T>
   void BitSwitch<T>::Set()
   {
      memset( &m_Flags, 0xFF, sizeof( m_Flags ) );
   }

   template<typename T>
   void BitSwitch<T>::Set( const uint8_t& a_Pos )
   {
      m_Flags |= GetBitMask( a_Pos );
   }

   template<typename T>
   void BitSwitch<T>::Reset()
   {
      m_Flags = 0;
   }

   template<typename T>
   void BitSwitch<T>::Reset( const uint8_t& a_Pos )
   {
      m_Flags &= ~GetBitMask( a_Pos );
   }

   template<typename T>
   void BitSwitch<T>::Flip()
   {
      m_Flags = ~m_Flags;
   }

   template<typename T>
   void BitSwitch<T>::Flip( const uint8_t& a_Pos )
   {
      m_Flags ^= GetBitMask( a_Pos );
      //Set( a_Pos, !Value( a_Pos ) );
   }

   template<typename T>
   bool BitSwitch<T>::AreAllOn()
   {
      T x_MaxValue;
      memset( &x_MaxValue, 0xFF, sizeof( x_MaxValue ) );

      return m_Flags == x_MaxValue;
   }

   template<typename T>
   bool BitSwitch<T>::AreAllOff()
   {
      return m_Flags == 0;
   }

   template<typename T>
   bool BitSwitch<T>::AnyOn()
   {
      return m_Flags;
   }

   template<typename T>
   const T& BitSwitch<T>::Value()
   {
      return m_Flags;
   }

   template<typename T>
   const bool BitSwitch<T>::Value( const uint8_t& a_Pos )
   {
      return m_Flags & GetBitMask( a_Pos );
   }
}

