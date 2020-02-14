#include "Formatter.h"

namespace Compose
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formatter::Formatter( const Utils::StringExtract& a_FormatString )
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
            case Composition::OPENING_BRACE:
               if ( i_ptr == a_FormatString.ExtractStart() )
                  x_SectionStart = a_FormatString.ExtractStart() + 1;
               else if ( !x_ReadingStringLitteral )
                  throw; // TODO Exception Unexpected { in format string.
               break;

            case Composition::CLOSING_BRACE:
               if ( i_ptr == a_FormatString.ExtractEnd() )
               {
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
               break;

            case Composition::STRING_LITERAL_DELIMITER:
               if ( x_Section != FORMAT )
                  throw; // TODO Exception string litteral found outside format section.
               x_ReadingStringLitteral = x_ReadingStringLitteral ? false : true;
               break;

            default:
               break;
         }
      }

      this->ParseIndexExtract();

      if ( m_Aligned )
         this->ParseAlignmentExtract();

      if ( m_Formatted )
         this->ParseFormatExtract();
   }

   Formatter::~Formatter()
   {}

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void Formatter::ParseIndexExtract()
   {
      const Utils::StringExtract& x_FormatString = GetStringExtractOfSection( INDEX );
      m_Index = 0;

      for ( const char* i_ptr = x_FormatString.ExtractStart(); i_ptr <= x_FormatString.ExtractEnd(); i_ptr++ )
      {
         m_Index *= 10;

         if ( *i_ptr >= '0' && *i_ptr <= '9' )
            m_Index += ( *i_ptr - '0' );
         else
            throw; // TODO Exception index is not a number.
      }
   }

   void Formatter::ParseAlignmentExtract()
   {
      const Utils::StringExtract& x_FormatString = GetStringExtractOfSection( ALIGNMENT );
      m_Alignment = 0;
      bool x_AlignLeft = *x_FormatString.ExtractStart() == '-';

      for ( const char* i_ptr = x_FormatString.ExtractStart(); i_ptr <= x_FormatString.ExtractEnd(); i_ptr++ )
      {
         if ( x_AlignLeft  )
            continue;
         
         m_Alignment *= 10;

         if ( *i_ptr >= '0' && *i_ptr <= '9' )
            m_Alignment += ( *i_ptr - '0' );
         else
            throw; // TODO Exception index is not a number.
      }

      if ( x_AlignLeft )
         m_Alignment *= -1;
   }

   void Formatter::ParseFormatExtract()
   {
      const Utils::StringExtract& x_FormatString = GetStringExtractOfSection( FORMAT );
   }

   const Utils::StringExtract& Formatter::GetStringExtractOfSection( Formatter::StringFormatSection a_Section ) const
   {
      switch ( a_Section )
      {
         case INDEX:
            return *m_IndexExtract;
            break;
         case ALIGNMENT:
            return *m_AlignmentExtract;
            break;
         case FORMAT:
            return *m_FormatExtract;
            break;
         default:
            throw; // TODO Exception Unknown StringFormatSection value.
            break;
      }
   }
}