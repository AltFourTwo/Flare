#include "FlarePCH.h"
#include "VertexBufferLayout.h"

#include <glfw/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{
   /*****   NESTED  CLASSES      *****/
   // VertexBufferElement Functions
   unsigned int VertexBufferElement::GetSizeOfType( unsigned int a_Type ) 
   {
      switch ( a_Type )
      {
         case GL_FLOAT:
            return sizeof( GLfloat );
         case GL_UNSIGNED_INT:
            return sizeof( GLuint );
         case GL_UNSIGNED_BYTE:
            return sizeof( GLubyte );
      }
      ASSERT( false, "Could not get the size of type [" << a_Type << "]" );
      return 0;
   }

   /*****   CLASS   C-TOR D-TOR  *****/
   VertexBufferLayout::VertexBufferLayout() :
      m_Stride( 0 )
   {}

   VertexBufferLayout::~VertexBufferLayout()
   {

   }

   /*****   CLASS   FUNCTIONS    *****/
   void VertexBufferLayout::Push_Float( unsigned int a_Count )
   {
      m_Elements.push_back( { GL_FLOAT, a_Count, GL_FALSE } );
      m_Stride += a_Count * VertexBufferElement::GetSizeOfType( GL_FLOAT );
   }

   void VertexBufferLayout::Push_Unsigned_Int( unsigned int a_Count )
   {
      m_Elements.push_back( { GL_UNSIGNED_INT, a_Count, GL_FALSE } );
      m_Stride += a_Count * VertexBufferElement::GetSizeOfType( GL_UNSIGNED_INT );
   }

   void VertexBufferLayout::Push_Unsigned_Char( unsigned int a_Count )
   {
      m_Elements.push_back( { GL_UNSIGNED_BYTE, a_Count, GL_TRUE } );
      m_Stride += a_Count * VertexBufferElement::GetSizeOfType( GL_UNSIGNED_BYTE );
   }
}