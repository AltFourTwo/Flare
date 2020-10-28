#pragma once
#include "IObject.h"

#include <string>

namespace Flare::Rendering
{
   class Shader : public IObject
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~Shader() {};

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Shader* Create( const std::string& a_VertexSource, const std::string& a_PixelSource );
   };
}