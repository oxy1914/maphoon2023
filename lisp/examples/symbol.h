
// The code below was generated by Maphoon 2021.

// Definition of struct symbol:

#ifndef SYMBOL
#define SYMBOL    1

#include <iostream>
#include <variant>
#include <optional>
#include <stdexcept>

#line 15 "grammar.m"
 #include <filereader.h> 
 #include "ast/ast.h" 
 #include <bigint.h> 
 #include <vector> 
 #include <memory> 

struct location{
  long unsigned int line;
  long unsigned int column;

  location() {}
  location( long unsigned int line,
            long unsigned int column )
            : line( line ),
              column( column )
  { }
};


enum symboltype
{
   sym__recover_, sym_S_EXPR, sym_LIST, sym_EOF, 
   sym_ERROR, sym_INT, sym_COMMENT, sym_FLOAT, 
   sym_LIST_REST, sym_EMPTY, sym_WHITESPACE, sym_ID, 
   sym_ATOM, sym_LPAR, sym_STR, sym_RPAR, 
   sym_QUOT
};

const char* getcstring( symboltype );

inline std::ostream& operator << ( std::ostream& out, symboltype tp )
   { out << getcstring( tp );  return out; }

struct symbol
{
   using attrtype = std::variant < std::monostate, double, std::string, 
         bigint, ast::listbp > ;

   using infotype = 
      std::optional< location > ;

   symboltype type;
   infotype info;
   attrtype attr;

   symbol( ) = delete;
   symbol( const symbol& ) = default;
   symbol( symbol&& ) noexcept = default;
   symbol& operator = ( const symbol& ) = default;
   symbol& operator = ( symbol&& ) noexcept = default;
   ~symbol( ) = default;

   symbol( symboltype type,
           const infotype& info )
    : type( type ),
      info( info )
   { }

   symbol( symboltype type,
           const infotype& info,
           attrtype && attr )
    : type( type ),
      info( info ),
      attr( std::move( attr ))
   { }

   symbol( symboltype type,
           const infotype& info,
           double attr )
    : type( type ),
      info( info ),
      attr( attr )
   { }

   symbol( symboltype type,
           const infotype& info,
           const std::string & attr )
    : type( type ),
      info( info ),
      attr( attr )
   { }

   symbol( symboltype type,
           const infotype& info,
           std::string && attr )
    : type( type ),
      info( info ),
      attr( std::move( attr ))
   { }

   symbol( symboltype type,
           const infotype& info,
           const bigint & attr )
    : type( type ),
      info( info ),
      attr( attr )
   { }

   symbol( symboltype type,
           const infotype& info,
           bigint && attr )
    : type( type ),
      info( info ),
      attr( std::move( attr ))
   { }

   symbol( symboltype type,
           const infotype& info,
           const ast::listbp & attr )
    : type( type ),
      info( info ),
      attr( attr )
   { }

   symbol( symboltype type,
           const infotype& info,
           ast::listbp && attr )
    : type( type ),
      info( info ),
      attr( std::move( attr ))
   { }


   void print( std::ostream& out ) const;

   template< typename T > const T& get( ) const
      { return std::get<T> ( attr ); }
   
   template< typename T > T& get( )
      { return std::get<T> ( attr ); }
   
};

inline
std::ostream& operator << ( std::ostream& out, const symbol& sym )
   { sym. print( out ); return out; }


#endif


