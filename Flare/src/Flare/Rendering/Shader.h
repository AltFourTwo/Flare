#pragma once
#include "IRendererBindable.h"
#include "RenderingController.h"
#include "ShaderToken.h"

#include <string>

namespace Flare::Rendering
{
   class Shader : public IRendererBindable
   {
      /*****  C-TOR D-TOR  *****/
      public:
      virtual ~Shader() = default;

      /*****   FUNCTIONS   *****/
      public:
      static Ref<Shader> Create( const std::string& a_Source ); // TODO Replace with a Shader Asset Specialization.
      static Ref<Shader> Create( const std::string& a_VertexSource, const std::string& a_PixelSource );

      // This will be for later, a simple casting of the shader into specialized type should allow uniform uploading.
      // I don't want to just write a bunch of code that won't serve much purpose for now.
      // virtual void UploadUniformMat4( const std::string& a_Name, const glm::mat4 a_Matrix );
   };
}