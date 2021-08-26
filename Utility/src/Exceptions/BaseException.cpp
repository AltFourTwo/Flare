#include "UtilityPCH.h"

#include <exception>
#include <string>

#include "BaseException.h"

#include <format>

namespace Utility::Exceptions
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   BaseException::BaseException( const char*& a_ErrorCode, const char* a_Message ) :
      m_Message()
   {
      std::string x_Code = a_ErrorCode;
      std::string x_Mess = a_Message;

      m_Message = std::format( "[{0}] - An error occured. {1}", x_Code, x_Mess );
   }

   BaseException::BaseException( exception& a_InnerException, const char*& a_ErrorCode, const char* a_Message ) :
      m_Message()
   {
      std::string x_Code = a_ErrorCode;
      std::string x_Mess = a_Message;
      std::string x_InnerMessage = a_InnerException.what();

      m_Message = std::format( "[{0}] - An error occured. {1} {2}", x_Code, x_Mess, x_InnerMessage );
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* BaseException::what() const
   {
      return m_Message.c_str();
   }
}