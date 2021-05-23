#pragma once
#include "Flare/Core.h"

#include <string>

namespace Flare
{
   template<typename T>
   class Resource
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      Scope<T> m_BufferObject;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Resource(const std::string& a_Name);
      Resource(Scope<T> a_BufferObject, const std::string& a_Name );

      /*****   CLASS   FUNCTIONS    *****/
      public:
      Scope<T> LoadFromFile( const std::string& a_Name, const std::string& a_FileName);
      void Free();
   };
}