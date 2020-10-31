#pragma once

namespace Flare::Rendering
{
   class ShaderDataType
   {
      /*****   CLASS   CONSTANTS    *****/
      public:
      enum DataType
      {
         None = 0,
         Bool1 = 1,
         Bool2 = 2,
         Bool3 = 3,
         Bool4 = 4,
         Integer1 = 5,
         Integer2 = 6,
         Integer3 = 7,
         Integer4 = 8,
         UnsignedInteger1 = 9,
         UnsignedInteger2 = 10,
         UnsignedInteger3 = 11,
         UnsignedInteger4 = 12,
         Float1 = 13,
         Float2 = 14,
         Float3 = 15,
         Float4 = 16,
         Double1 = 17,
         Double2 = 18,
         Double3 = 19,
         Double4 = 20,
         Matrix2By2 = 21,
         Matrix2By3 = 22,
         Matrix2By4 = 23,
         Matrix3By2 = 24,
         Matrix3By3 = 25,
         Matrix3By4 = 26,
         Matrix4By2 = 27,
         Matrix4By3 = 28,
         Matrix4By4 = 29,
         Matrix2By2D = 30,
         Matrix2By3D = 31,
         Matrix2By4D = 32,
         Matrix3By2D = 33,
         Matrix3By3D = 34,
         Matrix3By4D = 35,
         Matrix4By2D = 36,
         Matrix4By3D = 37,
         Matrix4By4D = 38,
      };

      /*****   CLASS   VARIABLES    *****/
      public:
      DataType m_Type;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      ShaderDataType();
      ShaderDataType( DataType a_DataType );

      /*****   GETTERS   *****/
      public:
      const uint32_t GetComponentCount() const;
      const uint32_t GetSizeOfType() const;
      const char* GetNameOfType() const;

      /*****   CLASS   OPERATORS    *****/
      operator DataType() const { return m_Type; }
   };
}