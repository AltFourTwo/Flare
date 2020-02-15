#pragma once

#include "StringComp/Composition.h"
#include "StringComp/IFormattable.h"
#include <string>


class TestObject : public Compose::IFormattable
{
   public:

   int x = 0;
   int y = 0;

   const char* ToString()
   {
      return "TestObject";
   }

   const char* ToString( char*& ptr)
   {
      std::string stringe = ptr;
      stringe += " x: " + x;
      stringe += " y: " + y;
      stringe += ".";

      return stringe.c_str();
   }
};