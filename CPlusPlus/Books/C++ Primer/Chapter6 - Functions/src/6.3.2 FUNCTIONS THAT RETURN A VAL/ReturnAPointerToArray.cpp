#include <iostream>

using namespace std;


// using typedef
typedef int arrT[10];       // arrT is a synonym for the type array of ten ints
                            // using arrT = int[10]; => The equivalent of arrT

arrT* function(int);        // function returns a pointer to an array of 10 ints

// without typedef
int (*pFunction(int))[10];  // = pFunction(int) says that we can call the function with int argumetn
                            // = (*pFunction(int)) says we can dereference the result of that call.
                            // = (*pFunction(int))[10] says that dereferencing the result of a call to
                            //   pFunction yields an array of size ten
                            // = int (*pFunction)[10] says the element type in that array is int.    

// using Trailing Return Type
auto theFunction(int) -> int(*)[10];
                      /* /\
                         |__this is the return type */

// using decltype
int odd[] = {1,3,5,7,9};
int even[] = {0, 2, 4, 6, 8};

// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;  // returns a pointer to the array
}