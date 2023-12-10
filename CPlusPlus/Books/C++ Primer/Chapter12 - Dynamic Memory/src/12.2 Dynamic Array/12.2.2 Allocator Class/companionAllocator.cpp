/*
As an example, assume we have a vector of ints that we want to copy into
dynamic memory. We’ll allocate memory for twice as many ints as are in the
vector. We’ll construct the first half of the newly allocated memory by copying
elements from the original vector. We’ll construct elements in the second half by
filling them with a given value:
*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,6,7,8,9};
    allocator<int> allocInt;                // object that will allocate memory

    int *pInt = allocInt.allocate(vint.size() * 2);     // allocate memory twice the size of vint

    // fill the first half of the constructed memory with value from vector
    int *q = uninitialized_copy(vint.cbegin(), vint.cend(), pInt);  // q will point to the one past the last element
    
    /*
    Like copy, uninitialized_copy returns its (incremented) destination iterator. 
    Thus, a call to uninitialized_copy returns a pointer positioned one element past the last constructed element. 
    */

    // initialize the remaining elements to 42
    q = uninitialized_fill_n(q, vint.size(), 42);

    // destroy first
    while (q != pInt)
        allocInt.destroy(--q);
    
    // now delete the memory
    allocInt.deallocate(pInt, vint.size() * 2);

    return 0;

}