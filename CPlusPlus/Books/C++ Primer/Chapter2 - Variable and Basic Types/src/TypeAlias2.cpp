#include <iostream>

using namespace std;

const int ci = 0, &cj = ci;

/* 
= When the expression to which we apply decltype is a variable,
  decltype returns the type of that variable, including top-level
  const and references.
*/

decltype(ci) x = 0;     // x has type const int
decltype(cj) y = x;     // y has type const int & and is bound to x

int i = 42, *p = &i, &r = i;

decltype(r + 0) b;      // ok: addition yields an int; b is an (uninitialized) int
/* 

    decltype(*p) c;         // error: c is int& and must be initialized

= the dereference operator is an example of an expression for which decltype
  returns a reference
  = Why ? because we get the object to which the pointer points

    decltype((i)) d;        // error: d is int& and must be initialized
    decltype(i) e;          // ok: e is an (uninitialized) int


= if we wrap the variable's name in one or more sets of parentheses, the compiler
  will evaluate the operand as an expression
  = A variable is an expression that can be the left-hand side of an assignment
  = so the decltype of a parenthesized varaible is always a reference
*/
