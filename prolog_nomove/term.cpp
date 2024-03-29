
// This code was generated by treebuilder

#include "term.h"

prolog::term::term( const term& from )
   : ssss( from. ssss )
{
   // std::cout << "term( const term& " << from. ssss << " )";
   
   switch( from. ssss )
   {
   case sel_atom:
      tvm::init( repr. fld00. loc, from. repr. fld00. loc );
      break;
   case sel_bigint:
      repr. fld01. heap = takeshare( from. repr. fld01. heap );
      break;
   case sel_double:
      tvm::init( repr. fld02. loc, from. repr. fld02. loc );
      break;
   case sel_functional:
      repr. fld03. heap = takeshare( from. repr. fld03. heap );
      break;
   case sel_int:
      tvm::init( repr. fld04. loc, from. repr. fld04. loc );
      break;
   case sel_var:
   case sel_string:
      tvm::init( repr. fld05. loc, from. repr. fld05. loc );
      break;
   }
}

// Note that the implementation of assignment is minimalistic.
// One should create special cases were *this and from are 
// in the same state.

const prolog::term & prolog::term::operator = ( const term& from )
{
   switch( from. ssss )
   {
   case sel_bigint:
      takeshare( from. repr. fld01. heap );
      break;
   case sel_functional:
      takeshare( from. repr. fld03. heap );
      break;
   }

   this -> ~term( );
   
   ssss = from. ssss;

   switch( ssss )
   {
   case sel_atom:
      tvm::init( repr. fld00. loc, from. repr. fld00. loc );
      break;
   case sel_bigint:
      repr. fld01. heap = from. repr. fld01. heap;
      break;
   case sel_double:
      tvm::init( repr. fld02. loc, from. repr. fld02. loc );
      break;
   case sel_functional:
      repr. fld03. heap = from. repr. fld03. heap;
      break;
   case sel_int:
      tvm::init( repr. fld04. loc, from. repr. fld04. loc );
      break;
   case sel_var:
   case sel_string:
      tvm::init( repr. fld05. loc, from. repr. fld05. loc );
      break;
   }

   return *this;
}


prolog::term::~term( ) noexcept
{
   switch( ssss )
   {
   case sel_atom:
      tvm::destroy( repr. fld00. loc );
      break;
   case sel_bigint:
      dropshare( repr. fld01. heap );
      break;
   case sel_double:
      tvm::destroy( repr. fld02. loc );
      break;
   case sel_functional:
      dropshare( repr. fld03. heap );
      break;
   case sel_int:
      tvm::destroy( repr. fld04. loc );
      break;
   case sel_var:
   case sel_string:
      tvm::destroy( repr. fld05. loc );
      break;
   }
}

bool prolog::term::very_equal_to( const term & other ) const
{
   if( ssss != other. ssss )
      return false;

   switch( ssss )
   {
   case sel_atom:
      if( !tvm::very_equal( repr. fld00. loc, other. repr. fld00. loc ))
         return false;
      return true;
   case sel_bigint:
      if( repr. fld01. heap != other. repr. fld01. heap )
         return false;
      return true;
   case sel_double:
      if( !tvm::very_equal( repr. fld02. loc, other. repr. fld02. loc ))
         return false;
      return true;
   case sel_functional:
      if( repr. fld03. heap != other. repr. fld03. heap )
         return false;
      return true;
   case sel_int:
      if( !tvm::very_equal( repr. fld04. loc, other. repr. fld04. loc ))
         return false;
      return true;
   case sel_var:
   case sel_string:
      if( !tvm::very_equal( repr. fld05. loc, other. repr. fld05. loc ))
         return false;
      return true;
   }
}

void prolog::term::printstate( std::ostream& out ) const
{
   switch( ssss )
   {
   case sel_bigint:
      tvm::printstate( repr. fld01. heap, out );
      break;
   case sel_functional:
      tvm::printstate( repr. fld03. heap, out );
      break;
   }
}

