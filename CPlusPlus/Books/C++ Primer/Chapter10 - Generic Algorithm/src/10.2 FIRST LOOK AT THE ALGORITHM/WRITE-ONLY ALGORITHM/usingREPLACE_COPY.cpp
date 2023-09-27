#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

/*
replace_copy. That algorithm takes a third iterator argument denoting a destination in which to write the
adjusted sequence

*/

int main(void) {
    list<int> lint {1,2,3,0,0,4,5,0,0,6,7,8,0,9,10};
    vector<int> vint;

    cout << "Before copy to vint: " << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    replace_copy(lint.begin(), lint.end(), back_inserter(vint), 0, 42);
    // after this call, lint is unchanged, and vint contains a copy of lint
    // with the exception that every element in lint with the value 0 replaced
    // by value 42

    cout << "After copy to vint: " << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;

}