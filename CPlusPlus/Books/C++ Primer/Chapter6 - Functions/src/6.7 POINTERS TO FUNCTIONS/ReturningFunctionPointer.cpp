#include <iostream>

using namespace std;

using F = int(int*, int);      //  F is a function type, nto a pointer
using PF = int(*)(int *, int);  // PF is a pointer type

PF f1(int);     // ok: PF is a pointer to function; f1 returns a pointer to function
// F f1(int);      // error: F is a function type; f1 can't return a function
F *f2(int);     // ok: explicityly specify that the return type is apointer to function

// without 'using' declaration
int (*f1(int))(int *, int);     // declare function that takes int parameter
                                // and return a pointer to function with int return type and two
                                // parameters.
auto f1(int) -> int (*)(int *, int);    // equivalent type