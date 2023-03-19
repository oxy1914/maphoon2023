
// The code below was generated by Maphoon 2023.

// Definition of struct symbol:

#ifndef SYMBOL_
#define SYMBOL_    1

#include <iostream>
#include <variant>
#include <optional>
#include <concepts>
#include <stdexcept>

#line 36 "grammar.m"
 #include "form.h" 

enum symboltype
{
   sym__recover_, sym_Index, sym_Var, sym_ID, 
   sym_WHITESPACE, sym_ERROR, sym_NOT, sym_NUMBER, 
   sym_IMP, sym_DIASTART, sym_COMMENT, sym_Session, 
   sym_AND, sym_DIAEND, sym_CONST, sym_RIGHTPAR, 
   sym_DIA, sym_LEFTPAR, sym_OR, sym_EOF, 
   sym_EQUIV, sym_SEMICOLON, sym_BOX, sym_BOXSTART, 
   sym_RETURN, sym_NNF, sym_BOXEND, sym_BECOMES, 
   sym_METAVAR, sym_Formula, sym_Command
};

const char* getcstring( symboltype );

inline std::ostream& operator << ( std::ostream& out, symboltype tp )
   { out << getcstring( tp );  return out; }

struct symbol
{
   using attrtype = std::variant < std::monostate, form, bool, 
         unsigned int, std::string, agent > ;

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

   template< typename _T = form > 
      requires std::copyable< _T > 
   symbol( symboltype type,
           const form & attr )
    : type( type ),
      attr( attr )
   { }

   template< typename _T = form > 
      requires std::is_nothrow_move_constructible_v< _T > 
   symbol( symboltype type,
           form && attr )
    : type( type ),
      attr( std::move( attr ))
   { }

   template< typename _T = bool > 
      requires std::is_nothrow_move_constructible_v< _T > 
   symbol( symboltype type,
           bool attr )
    : type( type ),
      attr( attr )
   { }

   template< typename _T = unsigned int > 
      requires std::is_nothrow_move_constructible_v< _T > 
   symbol( symboltype type,
           unsigned int attr )
    : type( type ),
      attr( attr )
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

   template< typename _T = agent > 
      requires std::copyable< _T > 
   symbol( symboltype type,
           const agent & attr )
    : type( type ),
      attr( attr )
   { }

   template< typename _T = agent > 
      requires std::is_nothrow_move_constructible_v< _T > 
   symbol( symboltype type,
           agent && attr )
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


#endif


