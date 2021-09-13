#pragma once
#include "Asset.h"

namespace Flare
{
   class FileAsset : public Asset
   {
      /*****   VARIABLES   *****/
      private:

      /*****  C-TOR D-TOR  *****/
      public:
      FileAsset( const std::string& a_Name = "Unnamed Asset", bool a_PersistentData = false );
      FileAsset( const FileAsset& x_Other ) = delete;
      virtual ~FileAsset();

      /*****   FUNCTIONS   *****/
      public:
      virtual void AfterLoadSetup() override;
      virtual void BeforeSaveSetup() override;

      std::string AsText();

      /*****   OPERATORS    *****/
      void operator=( const FileAsset& ) = delete;
   };
}