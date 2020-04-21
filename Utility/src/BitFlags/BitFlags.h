#pragma once

#include "Macros.h"

#include <cstdint>
#include <type_traits>

namespace BitFlags
{
   template<typename T>
   using as_integral_t = typename std::enable_if<std::is_integral<T>::value>::type;

   template<typename T>
   class ByteFlags
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      T m_Flags;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      ByteFlags( T a_IntegralValue, typename as_integral_t<T>* = nullptr );

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void SetAllFalse();
      void SetAllTrue();
      void SetFlags( T a_Flags, typename as_integral_t<T>* = nullptr );
      size_t FlagsSize();
      T MaxIntegralValue();
   };

   template<typename T>
   class SingleByteFlags : public ByteFlags<uint8_t>
   {
      SingleByteFlags( T a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE
   };

   template<typename T>
   class DoubleByteFlags : public ByteFlags<uint16_t>
   {
      DoubleByteFlags( T a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE
   };

   template<typename T>
   class QuadByteFlags : public ByteFlags<uint32_t>
   {
      QuadByteFlags( T a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE
   };

   template<typename T>
   class OctaByteFlags : public ByteFlags<uint64_t>
   {
      OctaByteFlags( T a_IntegralValue ) : ByteFlags( a_IntegralValue ) EMPTY_SCOPE
   };
}

