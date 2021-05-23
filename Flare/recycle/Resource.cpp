#include "FlarePCH.h"
#include "Resource.h"

#include "FileAsset.h"

namespace Flare
{
   /*****   CLASS   C-TOR D-TOR  *****/
   template<typename T>
   Resource<T>::Resource(const std::string& a_Name)
   {
      
   }

   template<typename T>
   Resource<T>::Resource( Scope<T> a_BufferObject, const std::string& a_Name )
   {

   }

   /*****   CLASS   FUNCTIONS    *****/
   template<typename T>
   Scope<T> Resource<T>::LoadFromFile( const std::string& a_Name, const std::string& a_FileName )
   {
      Asset::LoadAsset<T>( a_FileName, a_Name, true );
   }

   template<typename T>
   void Resource<T>::Free()
   {
      (Asset)m_BufferObject.Free();
   }
}