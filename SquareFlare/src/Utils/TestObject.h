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
      x( 0 ), y( 0 )
   {

   }

   ~TestObject()
   {

   }

   std::string Compose::IFormattable::ToString() const
   {
      return "TestObject";
   }

   std::string Compose::IFormattable::ToString( const char*& ptr ) const
   {
      std::string strange = ptr;
      strange += "x: ";
      strange += std::to_string( x );
      strange += " y: ";
      strange += std::to_string( y );

      return strange;
   }
};