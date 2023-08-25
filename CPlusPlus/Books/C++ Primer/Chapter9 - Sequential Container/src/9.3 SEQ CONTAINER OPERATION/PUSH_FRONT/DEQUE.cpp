#include <iostream>
#include <deque>

using namespace std;


int main(void) {
    deque<int> deqint {1,2,3};

    // display before push_front
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3
    */

    // insert two value in front of deqint
    deqint.push_front(5);
    deqint.push_front(7);

    // display after push_front
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /*
        7 5 1 2 3
    */

    return 0;
}