#include "UtilityPCH.h"

#include <cstdint>
#include <type_traits>

#include "BitFlags.h"

namespace BitFlags
{
   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   ByteFlags<T>::ByteFlags( T a_IntegralValue, typename as_integral_t<T>* )
      : m_Flags( a_IntegralValue )
   {

   }

   /*****   CLASS   FUNCTIONS    *****/
   template<typename T>
   void ByteFlags<T>::SetAllFalse()
   {
      m_Flags = 0;
   }

   template<typename T>
   void ByteFlags<T>::SetAllTrue()
   {
      m_Flags = this->MaxIntegralValue();
   }

   template<typename T>
   void ByteFlags<T>::SetFlags( T a_Flags, typename as_integral_t<T>* )
   {
      m_Flags = a_Flags;
   }

   template<typename T>
   size_t ByteFlags<T>::FlagsSize()
   {
      return sizeof( T );
   }

   template<typename T>
   T ByteFlags<T>::MaxIntegralValue()
   {
      switch ( this->FlagsSize() )
      {
         case 1: return UINT8_MAX;
         case 2: return UINT16_MAX;
         case 4: return UINT32_MAX;
         case 8: return UINT64_MAX;
         default: throw; // TODO Exception Unexpected Number of bytes
      }
   }
}