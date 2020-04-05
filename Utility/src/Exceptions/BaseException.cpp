#include "UtilityPCH.h"

#include <exception>
#include <string>

#include "BaseException.h"

#include "Composing/Composition.h"

namespace Utility::Exceptions
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   BaseException::BaseException( std::string& a_ErrorCode, exception& a_InnerException ) :
      m_ErrorCode( a_ErrorCode ),
      m_InnerException( a_InnerException )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* BaseException::what()
   {
      return Composing::Format( "[{0}] - An error occured. {1}", { m_ErrorCode, m_InnerException.what() } ).c_str();
   }
}