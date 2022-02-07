#include "FlarePCH.h"
#include "ResourceManager.h"

#include "Flare/Core/Assert.h"
#include "Flare/Core/Log.h"
#include "FileAsset.h"

namespace Flare
{
   ResourceManager* ResourceManager::s_Instance = nullptr;

   /*****  C-TOR D-TOR  *****/
   ResourceManager::ResourceManager() noexcept :
      m_ResourceMap()
   {}

   ResourceManager::~ResourceManager() noexcept
   {
      // TODO Close open handles ?

      m_ResourceMap.clear();
   }

   /*****   FUNCTIONS   *****/
   ResourceManager& ResourceManager::Initialize()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::ResouceManager aleady exists!" ); // TODO more logs & error codes.
      s_Instance = new ResourceManager();

      return *s_Instance;
   }
}