#include <iostream>
#include <deque>
#include <string>

/* 2. Iterator, pointer and references to a deque are invalid if we add element
   anywhere but at the front or back. 
   2.1 If we add at the front or back, iterators
   are invalidate, but references and pointers to existing elements are not.
*/

using namespace std;

int main(void) {
    deque<string> deqStr {"Muhammad", "Akbar"};
    deque<string>::iterator deqStr_begin = deqStr.end() - 1;
    deque<string>::reference firstElement = deqStr.at(1);

    cout << "The address of each element before insertion: " << endl;
    for (const string &str: deqStr)
        cout << &str << " " << str << endl;
    
    cout << "The iterator deqStr_begin: " << &(*deqStr_begin) << endl;
    cout << "The reference first_element: " << &firstElement << endl;

    // insertion
    deqStr.insert(deqStr_begin, {"faza", "akbar"});

    cout << "The address of each element after insertion: " << endl;
    for (const string &str: deqStr)
        cout << &str << " " << str << endl;
    
    cout << "The iterator deqStr_begin: " << &(*deqStr_begin) << endl;
    cout << "The reference first_element: " << &firstElement << endl;

    return 0;
}
/*
The address of each element before insertion: 
    0x7f9b75008800 Muhammad
    0x7f9b75008818 Akbar
    The iterator deqStr_begin: 0x7f9b75008818
    The reference first_element: 0x7f9b75008818
    The address of each element after insertion: 
    0x7f9b75008800 Muhammad
    0x7f9b75008818 faza
    0x7f9b75008830 Akbar
    The iterator deqStr_begin: 0x7f9b75008818
    The reference first_element: 0x7f9b75008818
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2
    The address of each element before insertion: 
    0x7f88e5808800 Muhammad
    0x7f88e5808818 Akbar
    The iterator deqStr_begin: 0x7f88e5808818
    The reference first_element: 0x7f88e5808818
    The address of each element after insertion: 
    0x7f88e5808800 Muhammad
    0x7f88e5808818 faza
    0x7f88e5808830 akbar
    0x7f88e5808848 Akbar
    The iterator deqStr_begin: 0x7f88e5808818
    The reference first_element: 0x7f88e5808818
*/