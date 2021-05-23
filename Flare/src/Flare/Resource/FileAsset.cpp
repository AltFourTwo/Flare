#include "FlarePCH.h"
#include "FileAsset.h"

namespace Flare
{
   /*****   CLASS   C-TOR D-TOR  *****/
   FileAsset::FileAsset( const std::string& a_Name, bool a_PersistentData) :
      Asset( a_Name, a_PersistentData )
   {}

   FileAsset::~FileAsset() {}

   /*****   CLASS   FUNCTIONS    *****/
   void FileAsset::BeforeSaveSetup() {}
   void FileAsset::AfterLoadSetup() {}
}
