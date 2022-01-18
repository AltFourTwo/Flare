#pragma once

#include "Event.h"

namespace Flare::Events
{
   class ClipboardEvent : public Event
   {
      /*****   VARIABLES   *****/
      protected:
      const char* m_Data;

      /*****  C-TOR D-TOR  *****/
      protected:
      ClipboardEvent( const char* x_Data ) :
         m_Data( x_Data )
      {}

      /*****   GETTERS   *****/
      public:
      const char* GetData() { return m_Data; }
      virtual uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>( EventCategory::Clipboard ); }
   };

   class ClipboardCutEvent : public ClipboardEvent
   {
      /*****  C-TOR D-TOR  *****/
      protected:
      ClipboardCutEvent( const char* x_Data ) :
         ClipboardEvent( x_Data )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipboardCutEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::ClipboardCut; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "ClipboardCut"; }
   };

   class ClipboardCopyEvent : public ClipboardEvent
   {
      /*****  C-TOR D-TOR  *****/
      protected:
      ClipboardCopyEvent( const char* x_Data ) :
         ClipboardEvent( x_Data )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipboardCopyEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::ClipboardCopy; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "ClipboardCopy"; }
   };

   class ClipboardPasteEvent : public ClipboardEvent
   {
      /*****  C-TOR D-TOR  *****/
      protected:
      ClipboardPasteEvent( const char* x_Data ) :
         ClipboardEvent( x_Data )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "ClipboardPasteEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::ClipboardPaste; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "ClipboardPaste"; }
   };
}