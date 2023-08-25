#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3};

    // display before push_front
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3
    */

    // insert two value in front of lint
    lint.push_front(5);
    lint.push_front(7);

    // display after push_front
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;
    /*
        7 5 1 2 3
    */

    return 0;
}