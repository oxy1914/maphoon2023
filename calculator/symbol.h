
// The code below was generated by Maphoon 2023.

// Definition of struct symbol:

#ifndef SYMBOL_
#define SYMBOL_    1

#include <iostream>
#include <variant>
#include <optional>
#include <concepts>
#include <stdexcept>

#line 43 "grammar.m"
 #include <vector> 

enum symboltype
{
   sym__recover_, sym_EMPTY, sym_MODULO, sym_TIMES, 
   sym_LPAR, sym_PLUS, sym_G, sym_MINUS, 
   sym_RPAR, sym_Debug, sym_ASSIGN, sym_SEMICOLON, 
   sym_IDENT, sym_DIVIDES, sym_H, sym_Arguments, 
   sym_COMMA, sym_Command, sym_DOUBLE, sym_SCANERROR, 
   sym_Quit, sym_BAD, sym_EOF, sym_Nodebug, 
   sym_WHITESPACE, sym_FACTORIAL, sym_F, sym_E, 
   sym_Session, sym_Show, sym_COMMENT
};

const char* getcstring( symboltype );

inline std::ostream& operator << ( std::ostream& out, symboltype tp )
   { out << getcstring( tp );  return out; }

struct symbol
{
   using attrtype = std::variant < std::monostate, std::string, std::vector<double>, 
         double > ;

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

   template< typename _T = std::vector<double> > 
      requires std::copyable< _T > 
   symbol( symboltype type,
           const std::vector<double> & attr )
    : type( type ),
      attr( attr )
   { }

   template< typename _T = std::vector<double> > 
      requires std::is_nothrow_move_constructible_v< _T > 
   symbol( symboltype type,
           std::vector<double> && attr )
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


