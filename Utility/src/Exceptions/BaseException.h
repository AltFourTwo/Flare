#pragma once

#include <exception>

namespace Utility::Exceptions
{
   class BaseException : public std::exception
   {
      public:
      BaseException();
      ~BaseException();
   };

}