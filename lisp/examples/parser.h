

// Parser generated by Maphoon 2021.
// Written by Hans de Nivelle, March 2021.
// See the licence that was included with the code. 

#ifndef PARSER 
#define PARSER   1

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

#include "symbol.h"

#line 56 "grammar.m"
 #include "tokenizer.h" 
 #include "ast/ast.h" 
 #include <algorithm> 
#line 18 "idee.x"
 

struct parser
{

   struct statesymbol
   {
      size_t state;
      symboltype type;

      statesymbol( size_t state, symboltype type )
         : state( state ), type( type )
      { }

      struct hash
      {
         size_t operator( ) ( const statesymbol& ) const;
      };

      struct equal_to
      {
         bool operator( ) ( const statesymbol &, const statesymbol& ) const;
      };

      template< typename D > using map =
      std::unordered_map< statesymbol, D, hash, equal_to > ;
   };


   static std::unordered_map< symboltype,
      std::pair< size_t, std::unordered_set< symboltype >>> startsymbols;
      // Maps possible start symbols to pairs of
      // initial state, and terminator sets.

   static 
   std::vector< std::pair< char, size_t >> reductioninfo; 
      // Indexed by the states.
      // char = 'T' : the state consists of a single reduction (trivial).
      // char = 'D' : the state has a default reduction, which will be
      //              carried out when lookahead has no shift.
      // char = 'N' : the state has no reductions.
      // char = 'H' : none of the above. The state is hard.

   static statesymbol::map< size_t > shifts; 
   static statesymbol::map< std::vector< size_t >> reductions;

   std::vector< size_t > statestack;
   std::vector< symbol > symbolstack;
   std::optional< symbol > lookahead;

   unsigned int lasterror = 10000;
      // Time passed since the last error. 
      // (symbols that were processed.). 

   bool timetosaygoodbye = false; 
      // If you assign true, the parser will assume that 
      // it is really time to say goodbye. No more symbols will 
      // be read. 

   short int debug = 0;  
      // 0 : no output
      // 1 : only the parse stack
      // 2 : chosen shifts and reductions
      // 3 : attempted reductions. 

   // Parameters, defined by %parameters:

   filereader & r;
   tokenizer & tok;


   parser( filereader & r,
           tokenizer & tok )
      : r( r ),
        tok( tok )
   { }


   // i-th symbol on the symbolstack, looking backwards:
   // This means that 0 is undefined, 1 is .back( ), etc. 

   symbol& topsymbol( size_t i )
      { return *( symbolstack. end( ) - i ); }

   const symbol& topsymbol( size_t i ) const
      { return *( symbolstack. cend( ) - i ); }


   void reduce( symboltype lefttype, 
                symbol::attrtype&& attr, size_t rightsize );

   symbol parse( symboltype start );

   void print( std::ostream& out ) const;
      // Prints the state of the parser.

   unsigned int syntaxerror( );
      // When we encounter an error, the parser calls this function.
      // The number returned is the our patience when trying to recover.
      // 0 means that we do not try to recover at all. 10 means that 
      // we try to recover for 10 symbols, etc. 
      // 
      // First thing that the function should do is look at lasterror,
      // and decide if this is a new error, or a failure to recover from   
      // the previous error. 

   // Declarations of reduction functions and their conditions:
   // They have no arguments because they use the stack.

   ast::listbp body0( );
   ast::listbp body1( );
   ast::listbp body2( );
   ast::listbp body3( );
   ast::listbp body4( );
   ast::listbp body5( );
   ast::listbp body6( );
   ast::listbp body7( );
   ast::listbp body8( );
   ast::listbp body9( );


};

#endif

