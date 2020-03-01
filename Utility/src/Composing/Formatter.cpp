#include "UtilityPCH.h"

#include "Composition.h"
#include "Formatter.h"

namespace Composing
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formatter::Formatter( Utility::Strings::StringExtract& a_FormatString ) :
      m_WholeString( a_FormatString ),
      m_IndexExtract( 0, 0 ),
      m_AlignmentExtract( 0, 0 ),
      m_FormatExtract( 0, 0 )
   {
      if ( a_FormatString.ExtractStart() + 1 == a_FormatString.ExtractEnd() )
         throw; // TODO Exception Empty format string.

      StringFormatSection x_Section = INDEX;
      bool x_ReadingStringLitteral = false;
      const char* x_SectionStart;

      for ( const char* i_ptr = a_FormatString.ExtractStart(); i_ptr <= a_FormatString.ExtractEnd(); i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case OPENING_BRACE:
               if ( i_ptr == a_FormatString.ExtractStart() )
                  x_SectionStart = a_FormatString.ExtractStart() + 1;
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected { in format string.
               break;

            case CLOSING_BRACE:
               if ( i_ptr == a_FormatString.ExtractEnd() )
               {
                  if ( x_ReadingStringLitteral )
                     throw; // TODO Exception String litteral not closed.

                  if ( x_Section == INDEX )
                     m_IndexExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );
                  else if ( x_Section == ALIGNMENT )
                     m_AlignmentExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );
                  else
                     m_FormatExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );
               }
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected } in format string.
               break;

            case ALIGNMENT_SEPARATOR:
               if ( x_ReadingStringLitteral )
                  break;
               else if ( m_Aligned && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected , after alignment has been defined.

               if ( x_Section == INDEX )
                  m_IndexExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );
               else if ( x_Section == FORMAT )
                  m_FormatExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );

               m_Aligned = true;
               x_Section = ALIGNMENT;
               x_SectionStart = i_ptr + 1;
               break;

            case FORMAT_SPERATOR:
               if ( x_ReadingStringLitteral )
                  break;
               else if ( m_Formatted && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected : in format string.

               if ( x_Section == INDEX )
                  m_IndexExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );
               else if ( x_Section == ALIGNMENT )
                  m_AlignmentExtract = Utility::Strings::StringExtract( x_SectionStart, i_ptr - 1 );

               m_Formatted = true;
               x_Section = FORMAT;
               x_SectionStart = i_ptr + 1;
               break;

            case STRING_LITERAL_DELIMITER:
               if ( x_Section != FORMAT )
                  throw; // TODO Exception String litteral found outside format section.
               x_ReadingStringLitteral = x_ReadingStringLitteral ? false : true;
               break;

            default:
               break;
         }
      }

      this->ParseIndexExtract();

      if ( m_Aligned )
         this->ParseAlignmentExtract();
   }

   Formatter::~Formatter()
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string Formatter::FormatObject( const Formattable& a_Object ) const
   {
      if ( !m_Aligned && !m_Formatted )
         return a_Object.ToString();

      std::string x_FormattedObject;

      if ( m_Formatted )
      {
         std::string x_Format;
         x_Format.reserve( m_FormatExtract.Length() );
         bool x_ReadingStringLiteral = false;

         for ( const char* i_ptr = m_FormatExtract.ExtractStart(); i_ptr <= m_FormatExtract.ExtractEnd(); i_ptr++ )
         {
            switch ( *i_ptr )
            {
               case STRING_LITERAL_DELIMITER:
                  if ( x_ReadingStringLiteral )
                     x_ReadingStringLiteral = false;
                  else
                  {
                     x_ReadingStringLiteral = true;
                     if ( x_Format.length() > 0 )
                     {
                        const char* x_Cstr = x_Format.c_str();
                        x_FormattedObject += a_Object.ToString( x_Cstr );
                        x_Format.clear();
                     }
                  }
                  break;

               default:
                  if ( x_ReadingStringLiteral )
                     x_FormattedObject += *i_ptr;
                  else
                     x_Format += *i_ptr;
                  break;
            }
         }

         if ( x_Format.length() > 0 )
         {
            const char* x_Cstr = x_Format.c_str();
            x_FormattedObject += a_Object.ToString( x_Cstr );
         }
      }
      else
         x_FormattedObject = a_Object.ToString();

      if ( m_Aligned )
      {
         std::string x_AlignedFormattedObject;
         x_AlignedFormattedObject.reserve( abs( m_Alignment ) );

         if ( m_Alignment > 0 )
         {
            int x_CharDiff = m_Alignment - x_FormattedObject.length();
            if ( x_CharDiff == 0 )
               return x_FormattedObject;

            if ( x_CharDiff > 0 )
            {
               x_AlignedFormattedObject.append( x_CharDiff, ' ' );
               x_AlignedFormattedObject.append( x_FormattedObject );
            }
            else
               x_AlignedFormattedObject.append( x_FormattedObject, abs( x_CharDiff ), m_Alignment );
         }
         else if ( m_Alignment < 0 )
         {
            int x_CharDiff = abs( m_Alignment ) - x_FormattedObject.length();
            if ( x_CharDiff == 0 )
               return x_FormattedObject;

            if ( x_CharDiff > 0 )
            {
               x_AlignedFormattedObject.append( x_FormattedObject );
               x_AlignedFormattedObject.append( x_CharDiff, ' ' );
            }
            else
               x_AlignedFormattedObject.append( x_FormattedObject, 0, abs( m_Alignment ) );
         }

         x_FormattedObject.swap( x_AlignedFormattedObject );
      }

      return x_FormattedObject;
   }

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void Formatter::ParseIndexExtract()
   {
      m_Index = 0;

      for ( const char* i_ptr = m_IndexExtract.ExtractStart(); i_ptr <= m_IndexExtract.ExtractEnd(); i_ptr++ )
      {
         m_Index *= 10;

         if ( *i_ptr >= '0' && *i_ptr <= '9' )
            m_Index += ( *i_ptr - '0' );
         else
            throw; // TODO Exception Index must be a positive number found '*i_ptr'.
      }
   }

   void Formatter::ParseAlignmentExtract()
   {
      m_Alignment = 0;
      bool x_AlignLeft = *m_AlignmentExtract.ExtractStart() == '-';

      for ( const char* i_ptr = m_AlignmentExtract.ExtractStart(); i_ptr <= m_AlignmentExtract.ExtractEnd(); i_ptr++ )
      {
         if ( x_AlignLeft && i_ptr == m_AlignmentExtract.ExtractStart() )
            continue;

         m_Alignment *= 10;

         if ( *i_ptr >= '0' && *i_ptr <= '9' )
            m_Alignment += ( *i_ptr - '0' );
         else
            throw; // TODO Exception Alignment is not a number.
      }

      if ( x_AlignLeft )
         m_Alignment *= -1;
   }
}