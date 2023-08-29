#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    // insert number after value 4
    deque<int> deqint {1,2,3,4,5};
    // point to element that has value 5
    deque<int>::iterator lastElement = deqint.begin() + 4;

    // display before insert value
    cout << "Deqint: " << endl;
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4 5
    */

    // insert
    deqint.insert(lastElement, 8, 9);       // insert 9, 8 times

    cout << "Deqint: " << endl;
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4 9 9 9 9 9 9 9 9 5 
    */

    return 0;
}