#include "UtilityPCH.h"

#include <cstdint>
#include <type_traits>
#include <bitset>

#include "BitMasks.h"
#include "BitFlags.h"

namespace BitFlags
{
   /***** BitReference *****/
   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   BitReference<T>::BitReference( const T& a_Flags, const T&& a_Mask ) :
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
      m_Flags(0)
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
      return BitReference( m_Flags, GetBitMask( a_Pos ) );
   }
}