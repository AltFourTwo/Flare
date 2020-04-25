#pragma once

#include "Macros.h"

#include <cstdint>
#include <type_traits>

namespace BitFlags
{
   template<typename T>
   class BitReference
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      const T& m_Flags;
      const T& m_Mask;

      private:
      BitReference( const T& a_Flags, const T&& a_Mask );
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
      /*****   CLASS   FRIENDS      *****/
      friend class BitReference<T>;

      /*****   CLASS   VARIABLES    *****/
      protected:
      T m_Flags;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ByteFlags();
      ByteFlags( T a_IntegralValue );

      /*****   CLASS   FUNCTIONS    *****/
      private:
      static const T&& GetBitMask( const uint8_t& a_Pos);

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
      SingleByteFlags() : ByteFlags() EMPTY_SCOPE;
      SingleByteFlags( const uint8_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE;
   };

   class DoubleByteFlags : public ByteFlags<uint16_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      DoubleByteFlags() : ByteFlags() EMPTY_SCOPE;
      DoubleByteFlags( const uint16_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE;
   };

   class QuadByteFlags : public ByteFlags<uint32_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      QuadByteFlags() : ByteFlags() EMPTY_SCOPE;
      QuadByteFlags( const uint32_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE;
   };

   class OctaByteFlags : public ByteFlags<uint64_t>
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OctaByteFlags() : ByteFlags() EMPTY_SCOPE;
      OctaByteFlags( const uint64_t& a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE;
   };
}

