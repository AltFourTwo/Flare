#pragma once

#include <cstdint>

namespace Utility::BitFlags
{
   template<typename T>
   class ByteFlags
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      T m_Flags;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ByteFlags();
      ByteFlags( T a_IntegralValue );

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
      const T& Value();
      const bool Value( const uint8_t& a_Pos );
   };

   class SingleByteFlags : public ByteFlags<uint8_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      SingleByteFlags() : ByteFlags() {}
      SingleByteFlags( const uint8_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) {}
   };

   class DoubleByteFlags : public ByteFlags<uint16_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      DoubleByteFlags() : ByteFlags() {}
      DoubleByteFlags( const uint16_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) {}
   };

   class QuadByteFlags : public ByteFlags<uint32_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      QuadByteFlags() : ByteFlags() {}
      QuadByteFlags( const uint32_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) {}
   };

   class OctaByteFlags : public ByteFlags<uint64_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OctaByteFlags() : ByteFlags() {}
      OctaByteFlags( const uint64_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) {}
   };

   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   ByteFlags<T>::ByteFlags() :
      m_Flags( 0 )
   {}

   template<typename T>
   ByteFlags<T>::ByteFlags( T a_IntegralValue ) :
      m_Flags( a_IntegralValue )
   {}

   /*****   CLASS   FUNCTIONS    *****/
   template<typename T>
   T ByteFlags<T>::GetBitMask( const uint8_t& a_Pos )
   {
      T x_Mask = 1;
      x_Mask <<= a_Pos;

      if ( !x_Mask )
         return x_Mask;
         // TODO Log a warning when result mask is 0. (Left shift overflow.)

      return x_Mask;
   }

   template<typename T>
   void ByteFlags<T>::Set()
   {
      memset( &m_Flags, 0xFF, sizeof( m_Flags ) );
   }

   template<typename T>
   void ByteFlags<T>::Set( const uint8_t& a_Pos )
   {
      m_Flags |= GetBitMask( a_Pos );
   }

   template<typename T>
   void ByteFlags<T>::Set( const uint8_t& a_Pos, const bool& a_Value )
   {
      if ( a_Value )
         Set( a_Pos );
      else
         Reset( a_Pos );
   }

   template<typename T>
   void ByteFlags<T>::Reset()
   {
      m_Flags = 0;
   }

   template<typename T>
   void ByteFlags<T>::Reset( const uint8_t& a_Pos )
   {
      m_Flags &= ~GetBitMask( a_Pos );
   }

   template<typename T>
   void ByteFlags<T>::Flip()
   {
      m_Flags = ~m_Flags;
   }

   template<typename T>
   void ByteFlags<T>::Flip( const uint8_t& a_Pos )
   {
      Set( a_Pos, !Value( a_Pos ) );
   }

   template<typename T>
   bool ByteFlags<T>::AreAllOn()
   {
      T x_MaxValue;
      memset( &x_MaxValue, 0xFF, sizeof( x_MaxValue ) );

      return m_Flags == x_MaxValue;
   }

   template<typename T>
   bool ByteFlags<T>::AreAllOff()
   {
      return m_Flags == 0;
   }

   template<typename T>
   const T& ByteFlags<T>::Value()
   {
      return m_Flags;
   }

   template<typename T>
   const bool ByteFlags<T>::Value( const uint8_t& a_Pos )
   {
      return m_Flags & GetBitMask( a_Pos );
   }
}

