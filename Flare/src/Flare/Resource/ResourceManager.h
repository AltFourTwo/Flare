#pragma once
#include "Flare/Core.h"

#include "Asset.h"

#include <concepts>
#include <string>
#include <unordered_map>

namespace Flare
{
   template<typename T>
   concept DerivedFromAsset = std::derived_from<T, Asset>;

   class ResourceManager
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static ResourceManager* s_Instance;
      mutable std::unordered_map<std::string, Ref<Asset>> m_ResourceMap;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      ResourceManager();
      ResourceManager( const ResourceManager& ) = delete;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      template<typename T> requires DerivedFromAsset<T>
      static Ref<T> CreateAsset( const std::string& a_Name = "Unnamed Asset", bool a_PersistentData = false )
      {
         // TODO Add to resource map.
         return std::make_shared<T>( a_Name, a_PersistentData );
      }
       
      template<typename T> requires DerivedFromAsset<T>
      static Ref<T> LoadAsset( const std::string& a_Filepath, const std::string& a_Name = "Unnamed Asset", bool a_PersistentData = false )
      {
         // TODO Add to resource map.
         Ref<T> x_Asset = CreateAsset<T>( a_Name, a_PersistentData );
         static_cast<Asset*>(x_Asset.get())->Load(a_Filepath);
         return x_Asset;
      }

      /*****   GETTERS   *****/
      public:
      inline static const ResourceManager& GetInstance() { return *s_Instance; }
   };
}