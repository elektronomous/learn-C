#include <iostream>
#include <array>

using namespace std;

int main(void) {
    array<int, 10> ia;                      // ten-default initialized ints
    array<int, 10> ia2 = {1,2,3,4,5,6,7};   // list initialization
    array<int, 10> ia3 = {42};              // the remaining elements are 0

    /* It's worth noting that we cannot copy or assign object of built-in
       array types, There's no restriction on Array library

       int digs[10] = {1,2,3,4,5,6,7,8,9,10};
       int cpy[10] = digs;                      // error: no copy or assignment for built-in arrays
    */
   array<int, 10> copyia2 = ia2;            // ok: so long as array types and size match
                                            // because the size of the array is the part of its type

    return 0;
}