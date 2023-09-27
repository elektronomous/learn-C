#include <iostream>

using namespace std;
/*
This algorithm takes three iterators. The first two denote an input range; the
third denotes the beginning of the destination sequence. 

It is essential that the destination passed to copy be at least as large as the
input range.

*/

int main(void) {
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];         /* a2 has the same size as a1 */

    // ret points just past the last element copied into a2
    int *ret = copy(begin(a1), end(a1), a2);    // copy a1 into a2

    /* 
       the value returned by copoy is the (incremented) value of its destination
       iterator. that is, ret will point just past the last element copied into a2
    */
    if (ret == end(a2))
        cout << "ret points to the past the last element" << endl;

    return 0;
}