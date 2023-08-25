#include <iostream>
#include <forward_list>

using namespace std;

int main(void) {
    forward_list<int> flint {1,2,3};

    // display before push_front
    for (const int &val: flint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3
    */

    // insert two value in front of flint
    flint.push_front(5);
    flint.push_front(7);

    // display after push_front
    for (const int &val: flint)
        cout << val << " ";
    cout << endl;
    /*
        7 5 1 2 3
    */

    return 0;
}