/*
#pragma once

#include <cstdint>

namespace BitFlags
{
   static const uint64_t S_ALL_BITS_ON = UINT64_MAX;
   static const uint64_t S_BYTE1_ON = 0x0000'0000'0000'00FFUi64;
   static const uint64_t S_BYTE2_ON = 0x0000'0000'0000'FF00Ui64;
   static const uint64_t S_BYTE3_ON = 0x0000'0000'00FF'0000Ui64;
   static const uint64_t S_BYTE4_ON = 0x0000'0000'FF00'0000Ui64;
   static const uint64_t S_BYTE5_ON = 0x0000'00FF'0000'0000Ui64;
   static const uint64_t S_BYTE6_ON = 0x0000'FF00'0000'0000Ui64;
   static const uint64_t S_BYTE7_ON = 0x00FF'0000'0000'0000Ui64;
   static const uint64_t S_BYTE8_ON = 0xFF00'0000'0000'0000Ui64;

   static const uint64_t S_ALL_BITS_OFF = 0x0000'0000'0000'0000Ui64;
   static const uint64_t S_BYTE1_OFF = 0xFFFF'FFFF'FFFF'FF00Ui64;
   static const uint64_t S_BYTE2_OFF = 0xFFFF'FFFF'FFFF'00FFUi64;
   static const uint64_t S_BYTE3_OFF = 0xFFFF'FFFF'FF00'FFFFUi64;
   static const uint64_t S_BYTE4_OFF = 0xFFFF'FFFF'00FF'FFFFUi64;
   static const uint64_t S_BYTE5_OFF = 0xFFFF'FF00'FFFF'FFFFUi64;
   static const uint64_t S_BYTE6_OFF = 0xFFFF'00FF'FFFF'FFFFUi64;
   static const uint64_t S_BYTE7_OFF = 0xFF00'FFFF'FFFF'FFFFUi64;
   static const uint64_t S_BYTE8_OFF = 0x00FF'FFFF'FFFF'FFFFUi64;

   static const uint64_t S_BIT01 = 0x0000'0000'0000'0001Ui64;
   static const uint64_t S_BIT02 = 0x0000'0000'0000'0002Ui64;
   static const uint64_t S_BIT03 = 0x0000'0000'0000'0004Ui64;
   static const uint64_t S_BIT04 = 0x0000'0000'0000'0008Ui64;
   static const uint64_t S_BIT05 = 0x0000'0000'0000'0010Ui64;
   static const uint64_t S_BIT06 = 0x0000'0000'0000'0020Ui64;
   static const uint64_t S_BIT07 = 0x0000'0000'0000'0040Ui64;
   static const uint64_t S_BIT08 = 0x0000'0000'0000'0080Ui64;

   static const uint64_t S_BIT09 = 0x0000'0000'0000'0100Ui64;
   static const uint64_t S_BIT10 = 0x0000'0000'0000'0200Ui64;
   static const uint64_t S_BIT11 = 0x0000'0000'0000'0400Ui64;
   static const uint64_t S_BIT12 = 0x0000'0000'0000'0800Ui64;
   static const uint64_t S_BIT13 = 0x0000'0000'0000'1000Ui64;
   static const uint64_t S_BIT14 = 0x0000'0000'0000'2000Ui64;
   static const uint64_t S_BIT15 = 0x0000'0000'0000'4000Ui64;
   static const uint64_t S_BIT16 = 0x0000'0000'0000'8000Ui64;

   static const uint64_t S_BIT17 = 0x0000'0000'0001'0000Ui64;
   static const uint64_t S_BIT18 = 0x0000'0000'0002'0000Ui64;
   static const uint64_t S_BIT19 = 0x0000'0000'0004'0000Ui64;
   static const uint64_t S_BIT20 = 0x0000'0000'0008'0000Ui64;
   static const uint64_t S_BIT21 = 0x0000'0000'0010'0000Ui64;
   static const uint64_t S_BIT22 = 0x0000'0000'0020'0000Ui64;
   static const uint64_t S_BIT23 = 0x0000'0000'0040'0000Ui64;
   static const uint64_t S_BIT24 = 0x0000'0000'0080'0000Ui64;

   static const uint64_t S_BIT25 = 0x0000'0000'0100'0000Ui64;
   static const uint64_t S_BIT26 = 0x0000'0000'0200'0000Ui64;
   static const uint64_t S_BIT27 = 0x0000'0000'0400'0000Ui64;
   static const uint64_t S_BIT28 = 0x0000'0000'0800'0000Ui64;
   static const uint64_t S_BIT29 = 0x0000'0000'1000'0000Ui64;
   static const uint64_t S_BIT30 = 0x0000'0000'2000'0000Ui64;
   static const uint64_t S_BIT31 = 0x0000'0000'4000'0000Ui64;
   static const uint64_t S_BIT32 = 0x0000'0000'8000'0000Ui64;

   static const uint64_t S_BIT33 = 0x0000'0001'0000'0000Ui64;
   static const uint64_t S_BIT34 = 0x0000'0002'0000'0000Ui64;
   static const uint64_t S_BIT35 = 0x0000'0004'0000'0000Ui64;
   static const uint64_t S_BIT36 = 0x0000'0008'0000'0000Ui64;
   static const uint64_t S_BIT37 = 0x0000'0010'0000'0000Ui64;
   static const uint64_t S_BIT38 = 0x0000'0020'0000'0000Ui64;
   static const uint64_t S_BIT39 = 0x0000'0040'0000'0000Ui64;
   static const uint64_t S_BIT40 = 0x0000'0080'0000'0000Ui64;

   static const uint64_t S_BIT41 = 0x0000'0100'0000'0000Ui64;
   static const uint64_t S_BIT42 = 0x0000'0200'0000'0000Ui64;
   static const uint64_t S_BIT43 = 0x0000'0400'0000'0000Ui64;
   static const uint64_t S_BIT44 = 0x0000'0800'0000'0000Ui64;
   static const uint64_t S_BIT45 = 0x0000'1000'0000'0000Ui64;
   static const uint64_t S_BIT46 = 0x0000'2000'0000'0000Ui64;
   static const uint64_t S_BIT47 = 0x0000'4000'0000'0000Ui64;
   static const uint64_t S_BIT48 = 0x0000'8000'0000'0000Ui64;

   static const uint64_t S_BIT49 = 0x0001'0000'0000'0000Ui64;
   static const uint64_t S_BIT50 = 0x0002'0000'0000'0000Ui64;
   static const uint64_t S_BIT51 = 0x0004'0000'0000'0000Ui64;
   static const uint64_t S_BIT52 = 0x0008'0000'0000'0000Ui64;
   static const uint64_t S_BIT53 = 0x0010'0000'0000'0000Ui64;
   static const uint64_t S_BIT54 = 0x0020'0000'0000'0000Ui64;
   static const uint64_t S_BIT55 = 0x0040'0000'0000'0000Ui64;
   static const uint64_t S_BIT56 = 0x0080'0000'0000'0000Ui64;

   static const uint64_t S_BIT57 = 0x0100'0000'0000'0000Ui64;
   static const uint64_t S_BIT58 = 0x0200'0000'0000'0000Ui64;
   static const uint64_t S_BIT59 = 0x0400'0000'0000'0000Ui64;
   static const uint64_t S_BIT60 = 0x0800'0000'0000'0000Ui64;
   static const uint64_t S_BIT61 = 0x1000'0000'0000'0000Ui64;
   static const uint64_t S_BIT62 = 0x2000'0000'0000'0000Ui64;
   static const uint64_t S_BIT63 = 0x4000'0000'0000'0000Ui64;
   static const uint64_t S_BIT64 = 0x8000'0000'0000'0000Ui64;
}
*/