#pragma once


namespace Flare::UserInput
{
   class Key
   {
      private:
      int m_Codes[5];

      public:
      Key( int Windows, int GLFW, int Linux, int Mac, int Potato )
      {
         m_Codes[0] = Windows;
         m_Codes[1] = GLFW;
         m_Codes[2] = Linux;
         m_Codes[3] = Mac;
         m_Codes[4] = Potato;
      }
   };

   class KeyMap
   {
      Key m_Keys[255];
   };
}