#pragma once

#include "Event.h"

namespace Flare::Events
{
   class FLARE_API ClipBoardEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      const char* m_Data;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ClipBoardEvent( const char* x_Data ) :
         m_Data( x_Data )
      {}

      /*****   GETTERS   *****/
      public:
      const char* GetData() { return m_Data; }
      FLARE_EVENT_CATEGORY( EventCategory::ClipBoard );
   };

   class FLARE_API ClipBoardCutEvent : public ClipBoardEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ClipBoardCutEvent( const char* x_Data ) :
         ClipBoardEvent( x_Data )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipBoardCutEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      FLARE_EVENT_TYPE( ClipBoardCut );
   };

   class FLARE_API ClipBoardCopyEvent : public ClipBoardEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ClipBoardCopyEvent( const char* x_Data ) :
         ClipBoardEvent( x_Data )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipBoardCopyEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      FLARE_EVENT_TYPE( ClipBoardCopy );
   };

   class FLARE_API ClipBoardPasteEvent : public ClipBoardEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ClipBoardPasteEvent( const char* x_Data ) :
         ClipBoardEvent( x_Data )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipBoardPasteEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      FLARE_EVENT_TYPE( ClipBoardPaste );
   };
}