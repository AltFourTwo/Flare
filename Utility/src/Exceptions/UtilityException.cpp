#include "UtilityPCH.h"

#include <exception>

#include "UtilityException.h"

#include "Composing/Composition.h"

namespace Utility::Exceptions
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   UtilityException::UtilityException( const char*& a_ErrorCode, const char* a_Message ) : BaseException( a_ErrorCode, a_Message )
   {}

   UtilityException::UtilityException( exception& a_InnerException, const char*& a_ErrorCode, const char* a_Message ) : BaseException( a_InnerException, a_ErrorCode, a_Message )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* UtilityException::what() const
   {
      return m_Message.c_str();
   }
}