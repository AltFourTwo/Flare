#include "FlarePCH.h"
#include "ResourceManager.h"

#include "Flare/Logging/Console.h"
#include "FileAsset.h"

namespace Flare
{
   ResourceManager* ResourceManager::s_Instance = nullptr;

   /*****   CLASS   C-TOR D-TOR  *****/
   ResourceManager::ResourceManager() :
      m_ResourceMap()
   {
      FLARE_CORE_ASSERT( !s_Instance, { "An instance of Flare::ResouceManager aleady exists!" } );
      s_Instance = this;
   }

   /*****   CLASS   FUNCTIONS    *****/
}