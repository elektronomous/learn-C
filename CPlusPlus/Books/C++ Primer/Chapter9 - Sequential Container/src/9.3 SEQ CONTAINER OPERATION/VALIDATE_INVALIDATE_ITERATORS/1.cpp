#include <iostream>
#include <vector>

/* Iterators, references, and pointers to a vector or string are invalid if
   the container was reallocated. If no reallocation happens, indirect references
   to element before the insertion remain valid; those to element after insertion
   are invalid.
*/

using namespace std;

int main(void) {
    vector<int> vint {1,2,3};
    vector<int>::iterator lastElement = vint.end() - 1;

    cout << "The address of each element before insertion: " << endl;
    for (const int &val: vint)
        cout << &val << endl;
    
    // the address of the last element
    cout << "The address of iterator to the last element: ";
    cout << &(*lastElement) << endl;

    // insertion
    vint.push_back(4);

    cout << "The address of each element after insertion: " << endl;
    for (const int &val: vint)
        cout << &val << endl;
    
    // still valid 
    cout << "The address of iterator to the last element: ";
    cout << &(*lastElement) << endl;
    

    return 0;    
}

/*

elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./1
The address of each element before insertion: 
    0x7fdc2e405870
    0x7fdc2e405874
    0x7fdc2e405878
The address of iterator to the last element: 0x7fbcd9405878
The address of each element after insertion: 
    0x7fdc2e405880
    0x7fdc2e405884
    0x7fdc2e405888
    0x7fdc2e40588c
The address of iterator to the last element: 0x7fbcd9405878
*/