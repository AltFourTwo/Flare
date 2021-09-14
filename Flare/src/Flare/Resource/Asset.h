#pragma once
#include "Flare/Core.h"

#include <string>

namespace Flare
{
   class Asset
   {
      /*****   VARIABLES   *****/
      private:
      std::string m_Name;
      std::string m_Filepath;
      size_t m_FileSize;
      Scope<char[]> m_FileBytes;
      bool m_PersistentData;

      /*****  C-TOR D-TOR  *****/
      public:
      Asset( const std::string& a_Name = "Unnamed Asset", bool a_PersistentData = false );
      Asset( const Asset& x_Other ) = delete;
      virtual ~Asset();

      /*****   FUNCTIONS   *****/
      protected:
      virtual void AfterLoadSetup() = 0;
      virtual void BeforeSaveSetup() = 0;

      public:
      void Free();
      void FreeIfNonPersistent();
      bool IsAlive();
      bool Load( const std::string& a_FilePath );
      bool Reload();
      void Save( const std::string& a_Filepath );

      /*****   OPERATORS    *****/
      void operator=( const Asset& ) = delete;

      /*****   GETTERS   *****/
      inline const std::string& GetName() const { return m_Name; }
      inline const std::string& GetFilepath() const { return m_Filepath; }
      inline size_t GetFileSize() const { return m_FileSize; }
      inline const char* GetBytes() const { return m_FileBytes.get(); }
   };
}
