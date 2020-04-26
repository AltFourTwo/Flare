#pragma once

#include <cstdint>

namespace Utility::BitFlags
{
   template<typename T>
   class ByteFlags;

   template<typename T>
   class BitReference
   {
      /*****   CLASS   FRIENDS      *****/
      friend class ByteFlags<T>;

      /*****   CLASS   VARIABLES    *****/
      private:
      const T& m_Flags;
      const T m_Mask;

      private:
      BitReference( const T& a_Flags, const T a_Mask );

      /*****   CLASS   FUNCTIONS    *****/
      void Set();
      void Set( const bool a_Value );
      void Reset();
      void Flip();
      bool Value() const;

      //void operator= // Basically Set
      //void operator~ // Basically Flip

      // Find a way to return Value() when called
   };

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
      static const T&& GetBitMask( const uint8_t& a_Pos );

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
      T Value();
      bool Value( const uint8_t& a_Pos );
      BitReference<T> BitRef( const int& a_Pos );
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

   /***** BitReference *****/
   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   BitReference<T>::BitReference( const T& a_Flags, const T a_Mask ) :
      m_Flags( a_Flags ),
      m_Mask( a_Mask )
      EMPTY_SCOPE;

   /*****   CLASS   FUNCTIONS    *****/
   template<typename T>
   void BitReference<T>::Set()
   {
      m_Flags |= m_Mask;
   }

   template<typename T>
   void BitReference<T>::Set( const bool a_Value )
   {
      if ( a_Value )
         Set();
      else
         Reset();
   }

   template<typename T>
   void BitReference<T>::Reset()
   {
      m_Flags &= ~m_Mask;
   }

   template<typename T>
   void BitReference<T>::Flip()
   {
      Set( !Value() );
   }

   template<typename T>
   bool BitReference<T>::Value() const
   {
      return m_Flags & m_Mask;
   }

   /***** ByteFlags *****/
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
   const T&& ByteFlags<T>::GetBitMask( const uint8_t& a_Pos )
   {
      T x_Bit = 1;

      return ( x_Bit << a_Pos );
   }

   template<typename T>
   void ByteFlags<T>::Set()
   {
      m_Flags = UINT64_MAX;
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
      m_Flags ~= m_Flags;
   }

   template<typename T>
   void ByteFlags<T>::Flip( const uint8_t& a_Pos )
   {
      Set( a_Pos, !Value( a_Pos ) );
   }

   template<typename T>
   bool ByteFlags<T>::AreAllOn()
   {
      return m_Flags == UINT64_MAX;
   }

   template<typename T>
   bool ByteFlags<T>::AreAllOff()
   {
      return m_Flags == 0;
   }

   template<typename T>
   T ByteFlags<T>::Value()
   {
      return m_Flags;
   }

   template<typename T>
   bool ByteFlags<T>::Value( const uint8_t& a_Pos )
   {
      T x_Mask = GetBitMask( a_Pos );

      return m_Flags & x_Mask;
   }

   template<typename T>
   BitReference<T> ByteFlags<T>::BitRef( const int& a_Pos )
   {
      return BitReference<T>::BitReference( ByteFlags::m_Flags, GetBitMask( a_Pos ) );
   }
}

