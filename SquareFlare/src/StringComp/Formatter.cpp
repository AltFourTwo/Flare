#include "Formatter.h"

namespace Compose
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formatter::Formatter( Utils::StringExtract& a_FormatString )
   {
      if ( a_FormatString.ExtractStart() + 1 == a_FormatString.ExtractEnd() )
         throw; // TODO Exception Empty format string.

      m_WholeString = &a_FormatString;

      StringFormatSection x_Section = INDEX;
      bool x_ReadingStringLitteral = false;
      const char* x_SectionStart;

      for ( const char* i_ptr = a_FormatString.ExtractStart(); i_ptr <= a_FormatString.ExtractEnd(); i_ptr++ )
      {
         switch ( *i_ptr )
         {
            case Composition::OPENING_BRACE:
               if ( i_ptr == a_FormatString.ExtractStart() )
                  x_SectionStart = a_FormatString.ExtractStart() + 1;
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected { in format string.
               break;

            case Composition::CLOSING_BRACE:
               if ( i_ptr == a_FormatString.ExtractEnd() )
               {
                  if ( x_ReadingStringLitteral )
                     throw; // TODO Exception String litteral not closed.

                  if ( x_Section == INDEX )
                     m_IndexExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );
                  else if ( x_Section == ALIGNMENT )
                     m_AlignmentExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );
                  else
                     m_FormatExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );
               }
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected } in format string.
               break;

            case Composition::ALIGNMENT_SEPARATOR:
               if ( m_Aligned && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unescaped second , in format string.

               if ( x_Section == INDEX )
                  m_IndexExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );
               else
                  m_FormatExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );

               m_Aligned = true;
               x_Section = ALIGNMENT;
               x_SectionStart = i_ptr + 1;
               break;

            case Composition::FORMAT_SPERATOR:
               if ( m_Formatted && !x_ReadingStringLitteral )
                  throw; // TODO Exception Unescaped second : in format string.

               if ( x_Section == INDEX )
                  m_IndexExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );
               else
                  m_AlignmentExtract = &Utils::StringExtract( x_SectionStart, i_ptr - 1 );

               m_Formatted = true;
               x_Section = FORMAT;
               x_SectionStart = i_ptr + 1;
               break;

            case Composition::STRING_LITERAL_DELIMITER:
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
   std::string Formatter::FormatObject( const IFormattable& a_Object )
   {
      if ( !m_Formatted )
         return a_Object.ToString();

      std::string x_Format;
      int x_index = 0;

      for ( const char* i_ptr = m_FormatExtract->ExtractStart(); i_ptr < m_FormatExtract->ExtractEnd(); i_ptr++ )
      {
         x_Format[x_index] = *i_ptr;
         x_index++;
      }

      const char* x_cstr = x_Format.c_str();

      return a_Object.ToString( x_cstr );
   }

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void Formatter::ParseIndexExtract()
   {
      m_Index = 0;

      for ( const char* i_ptr = m_IndexExtract->ExtractStart(); i_ptr <= m_IndexExtract->ExtractEnd(); i_ptr++ )
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
      bool x_AlignLeft = *m_AlignmentExtract->ExtractStart() == '-';

      for ( const char* i_ptr = m_AlignmentExtract->ExtractStart(); i_ptr <= m_AlignmentExtract->ExtractEnd(); i_ptr++ )
      {
         if ( x_AlignLeft && i_ptr == m_AlignmentExtract->ExtractStart() )
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