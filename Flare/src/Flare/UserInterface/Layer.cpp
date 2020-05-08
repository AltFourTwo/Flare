#include "FlarePCH.h"
#include "Layer.h"

namespace Flare::UserInterface
{
   /*****   CLASS   C-TOR D-TOR  *****/
   Layer::Layer( const std::string& a_Name ) :
      m_DebugName( a_Name )
   {}

   Layer::~Layer() {}
}