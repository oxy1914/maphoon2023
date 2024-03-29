
// The code below was generated by Maphoon 2023.

// Definition of struct symbol:

#ifndef PROLOG_SYMBOL_
#define PROLOG_SYMBOL_    1

#include <iostream>
#include <variant>
#include <optional>
#include <concepts>
#include <stdexcept>

#line 32 "grammar.m"
 #include "term.h" 
 #include "syntax.h" 
 #include "listconstr.h" 
 #include "termbasics.h" 

namespace prolog { 

   enum symboltype
   {
      sym_TERMINATOR, sym_BAR, sym_SomeTerms, sym__recover_, 
      sym_INTEGER, sym_VARIABLE, sym_DOUBLE, sym_RSQBRACKET, 
      sym_Postfix, sym_LSQBRACKET, sym_ListEnd, sym_Start, 
      sym_COMMENT, sym_IDENTIFIER, sym_Term, sym_MaybeTerms, 
      sym_OneTerm, sym_GLUEDQUOTEDIDENTIFIER, sym_ERROR, sym_COMMA, 
      sym_EOF, sym_LPAR, sym_Infix, sym_GLUEDIDENTIFIER, 
      sym_Prefix, sym_RPAR, sym_WHITESPACE, sym_QUOTEDIDENTIFIER
   };

   const char* getcstring( symboltype );

   inline std::ostream& operator << ( std::ostream& out, symboltype tp )
      { out << getcstring( tp );  return out; }

   struct symbol
   {
      using attrtype = std::variant < std::monostate, term, double, 
            opdef, std::string, bigint, std::vector<term> > ;

      symboltype type;
      attrtype attr;

      symbol( ) = delete;
      symbol( const symbol& ) = default;
      symbol( symbol&& ) noexcept = default;
      symbol& operator = ( const symbol& ) = default;
      symbol& operator = ( symbol&& ) noexcept = default;
      ~symbol( ) = default;

      symbol( symboltype type )
       : type( type )
      { }

      template< typename _T = attrtype > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const attrtype & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = attrtype > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              attrtype && attr )
       : type( type ),
         attr( std::move( attr ))
      { }

      template< typename _T = term > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const term & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = term > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              term && attr )
       : type( type ),
         attr( std::move( attr ))
      { }

      template< typename _T = double > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              double attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = opdef > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const opdef & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = opdef > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              opdef && attr )
       : type( type ),
         attr( std::move( attr ))
      { }

      template< typename _T = std::string > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const std::string & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = std::string > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              std::string && attr )
       : type( type ),
         attr( std::move( attr ))
      { }

      template< typename _T = bigint > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const bigint & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = bigint > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              bigint && attr )
       : type( type ),
         attr( std::move( attr ))
      { }

      template< typename _T = std::vector<term> > 
         requires std::copyable< _T > 
      symbol( symboltype type,
              const std::vector<term> & attr )
       : type( type ),
         attr( attr )
      { }

      template< typename _T = std::vector<term> > 
         requires std::is_nothrow_move_constructible_v< _T > 
      symbol( symboltype type,
              std::vector<term> && attr )
       : type( type ),
         attr( std::move( attr ))
      { }


      void print( std::ostream& out ) const;

      bool has_correct_attribute( ) const;

      template< typename T > T& get( )
         { return std::get<T> ( attr ); }
      
      template< typename T > const T& get( ) const
         { return std::get<T> ( attr ); }
      
   };

   inline
   std::ostream& operator << ( std::ostream& out, const symbol& sym )
      { sym. print( out ); return out; }


}

#endif


