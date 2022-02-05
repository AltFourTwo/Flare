#pragma once
#include "Flare/Core/Core.h"

#include "Flare/Resource/Asset.h"

#include <concepts>
#include <string>
#include <unordered_map>

namespace Flare
{
   template<typename T>
   concept DerivedFromAsset = std::derived_from<T, Asset>;

   class ResourceManager
   {
      /*****   VARIABLES   *****/
      private:
      static ResourceManager* s_Instance;
      mutable std::unordered_map<std::string, Ref<Asset>> m_ResourceMap;

      /*****  C-TOR D-TOR  *****/
      private:
      ResourceManager() noexcept;
      ~ResourceManager() noexcept;

      public:
      ResourceManager( const ResourceManager& ) = delete;

      /*****   FUNCTIONS   *****/
      public:
      static ResourceManager& Initialize();

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

      /*****   OPERATORS    *****/
      public:
      void operator=( const ResourceManager& ) = delete;

      /*****   GETTERS   *****/
      public:
      inline static const ResourceManager& GetInstance() { return *s_Instance; }
   };
}