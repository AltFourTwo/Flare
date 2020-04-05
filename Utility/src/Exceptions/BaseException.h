#pragma once

namespace Utility::Exceptions
{
   class BaseException : public std::exception
   {
      /******************************\
      \*****   PUBLIC-MEMBERS   *****/
      public:
      const std::string& m_ErrorCode;
      const exception& m_InnerException;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      BaseException( std::string& a_ErrorCode, exception& a_InnerException );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* what();
   };

}