#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1, 2, 3, 4};

    // display before inserting
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4
    */

    // copy 5 and then insert
    vint.push_back(5);

    // display after inserting
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 4 5 
    */

    return 0;
}