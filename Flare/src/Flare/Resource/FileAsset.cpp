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
   void FileAsset::AfterLoadSetup() {}
   void FileAsset::BeforeSaveSetup() {}

   std::string FileAsset::AsText()
   {
      std::string x_Text;
      x_Text.reserve(GetFileSize());
      x_Text.assign(GetBytes(), GetFileSize());
      return x_Text;
   }
}
