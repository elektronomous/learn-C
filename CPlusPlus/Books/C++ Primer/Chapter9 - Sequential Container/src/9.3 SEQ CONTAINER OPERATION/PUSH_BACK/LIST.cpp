#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4};

    // display before inserting one elemnet
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4
    */

    // copy 5 and then insert
    lint.push_back(5);

    // display after inserting one element
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4 5
    */

    return 0;
}