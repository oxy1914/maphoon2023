
// This code was automatically generated by treebuilder

#include "selector.h"

const char* prolog::getcstring( selector sel )
{
   switch( sel )
   {
   case sel_atom :
      return "sel_atom";
   case sel_var :
      return "sel_var";
   case sel_bigint :
      return "sel_bigint";
   case sel_double :
      return "sel_double";
   case sel_functional :
      return "sel_functional";
   case sel_int :
      return "sel_int";
   case sel_string :
      return "sel_string";
   }
   return "???";
}
