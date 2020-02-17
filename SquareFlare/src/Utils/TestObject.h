#pragma once

#include "SquareFlare/Core.h"
#include "StringComp/Composition.h"
#include "StringComp/IFormattable.h"
#include <string>


class TestObject : public Compose::IFormattable
{
   public:

   int x;
   int y;

   TestObject() :
      x(0), y(0)
   {

   }

   ~TestObject()
   {

   }

   const char* Compose::IFormattable::ToString() const
   {
      return "TestObject";
   }

   const char* Compose::IFormattable::ToString( const char*& ptr) const
   {
      std::string strange = ptr;
      strange += " x: " + x;
      strange += " y: " + y;
      strange += ".";

      return strange.c_str();
   }
};