#pragma once

#include "BaseException.h"

namespace Utility::Exceptions
{
   class UtilityException : public BaseException
   {
      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      UtilityException( const char*& a_ErrorCode, const char* a_Message );
      UtilityException( exception& a_InnerException, const char*& a_ErrorCode, const char* a_Message );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* what() const override;
   };

}
