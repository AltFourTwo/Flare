#pragma once

#include "Flare/Core.h"
#include "Composing/Composition.h"
#include "Composing/Formattables/IFormattable.h"

class TestObject : public Utility::Composing::IFormattable
{
   public:

   int x;
   int y;

   TestObject() :
      x( 0 ), y( 0 )
   {}

   ~TestObject()
   {}

   std::string IFormattable::ToString() const
   {
      return "TestObject";
   }

   std::string IFormattable::ToString( const char*& ptr ) const
   {
      std::string strange = ptr;
      strange += "x: ";
      strange += std::to_string( x );
      strange += " y: ";
      strange += std::to_string( y );

      return strange;
   }
};