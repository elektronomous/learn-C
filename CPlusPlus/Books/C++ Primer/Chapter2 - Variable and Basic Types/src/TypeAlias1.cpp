#include <iostream>

using namespace std;

typedef double wages;       // wages is a synonym for double
typedef wages base, *p;     // base is a synonym for double, p for double *


/* 

= top-level const can appear in any object type (arithmetic, class or pointer type)
= low-level const appears in the base type of compound types such pointers or references
= Note that only pointer types  can have both top-level and low-level
  = top-level const indicat that the pointer itself is a const
  = when a pointer can point to const object, we refer to that const as low-level const


*/

// C++ 11 standard define a second way
using I = int;              // I is a synonym for int

typedef char *pstring;

const pstring cstr = 0;     
/*     
    cstr is a constant pointer to char;
    the key to typedef is read from left to typedef definition (pstring in this case)
    (1) constant
    (2) pstring is pointer to char
    then you combine the (1) and (2) => constant pointer to char
    
        char *const cstr;
*/

 const pstring *ps;         
 /* 
    read from left
    (1) constant
    (2) pstring is pointer to char
    then you combine you get => pointer to constant pointer to char

        char *const *ps; 

*/

auto i = 20;
/*
i must be initialized because the job auto is to deduce the type from
initialzer.
*/

auto j = 20, *p = &j;
/* 
the base type must be same, j and p is int base type.

    auto sz = 0, pi = 3.14;     // error: inconsistent types for sz and pi
*/

int a = 0, &refToa = a;
auto toa = refToa;               // toa is an int (refToa is an alias for i, which has type int)

const int ci = i, &cr = ci;
auto b = ci;                    // b is an int (top-level const in ci is dropped)
auto c = cr;                    // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i;                    // d is an int* (& of an int object is int *)
auto e = &ci;                   // e is const int * (& of an const object is low-level const)

// to make const as top-level in auto
const auto f = ci;              // deduce type of ci is int; f has type const int
auto &g = ci;                   // g is reference to const int (const int &)
/* 
auto &h2 = 42;                  // error: we can't bind a plain reference to a literal
const auto &j = 42;             // ok: we can bind a const reference to a literal

= When we ask for reference to an auto-deduced type, top-level consts in the initializer are
  not ignored
*/
