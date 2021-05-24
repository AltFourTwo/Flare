#include "FlarePCH.h"
#include "Asset.h"

#include <fstream>
#include <filesystem>

namespace Flare
{
   /*****   CLASS   C-TOR D-TOR  *****/
   Asset::Asset( const std::string& a_Name, bool a_PersistentData ) :
      m_Name( a_Name ),
      m_Filepath( "" ),
      m_FileBytes( nullptr ),
      m_FileSize( 0 ),
      m_PersistentData( a_PersistentData )
   {}

   Asset::~Asset() {}

   /*****   CLASS   FUNCTIONS    *****/
   bool Asset::Load( const std::string& a_Filepath )
   {
      if ( !std::filesystem::exists( a_Filepath ) )
         return false;

      m_Filepath = a_Filepath;
      std::ifstream x_FileStream( a_Filepath, std::ios::in | std::ios::binary );

      if ( !x_FileStream )
         return false;

      // Getting the size of the file.
      x_FileStream.seekg( 0, std::ios::end );
      m_FileSize = x_FileStream.tellg();
      m_FileBytes.reset( new char[m_FileSize] );

      // Reading from begining to end into the buffer m_FileBytes.
      x_FileStream.seekg( 0, std::ios::beg );
      x_FileStream.read( m_FileBytes.get(), m_FileSize );
      x_FileStream.close();

      AfterLoadSetup();
      return true;
   }

   bool Asset::Reload()
   {
      return Load( m_Filepath );
   }

   void Asset::Free()
   {
      m_FileBytes.reset();
   }

   void Asset::FreeIfNonPersistent()
   {
      if ( m_PersistentData )
         Free();
   }

   bool Asset::IsAlive()
   {
      return m_FileBytes != nullptr;
   }

   void Asset::Save( const std::string& a_Filepath )
   {
      // TODO Save Thing. :)
   }
}
