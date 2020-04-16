#pragma once

namespace Utility::Exceptions
{
   class BaseException : public std::exception
   {
      /******************************\
      \*****   PUBLIC-MEMBERS   *****/
      public:
      std::string m_Message;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      BaseException( const char*& a_ErrorCode, const char* a_Message );
      BaseException( exception& a_InnerException, const char*& a_ErrorCode, const char* a_Message );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* what() const;
   };

}