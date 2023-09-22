/*
the fill_n function takes a single destination iterator, a count, and a value. 
It assigns the given value to the specified number of
elements starting at the element denoted to by the iterator.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};

    fill_n(vint.begin(), vint.size(), 0);   // reset all the elements of vint to 0
    // set 3 elements to be 10
    fill_n(vint.begin(), 3, 10);

    return 0;
}

/*
vector<int> vec; // empty vector
// disaster: attempts to write to ten (nonexistent) elements in vec
fill_n(vec.begin(), 10, 0);

Warning
Algorithms that write to a destination iterator assume the destination is large
enough to hold the number of elements being written.
*/