#pragma once
#include "Asset.h"

namespace Flare
{
   class FileAsset : public Asset
   {
      /*****   CLASS   VARIABLES    *****/
      private:

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      FileAsset( const std::string& a_Name = "Unnamed Asset", bool a_PersistentData = false );
      FileAsset( const FileAsset& x_Other ) = delete;
      virtual ~FileAsset();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void AfterLoadSetup() override;
      virtual void BeforeSaveSetup() override;

      std::string AsText();

      /*****   CLASS   OPERATORS    *****/
      void operator=( const FileAsset& ) = delete;
   };
}