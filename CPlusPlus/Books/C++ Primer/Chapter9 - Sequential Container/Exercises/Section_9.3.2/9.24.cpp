#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};

    if (!vint.empty()) {
        // access the first element using at
        cout << "using at: " << vint.at(0) << endl;
        // access the first element using subscript []
        cout << "using []: " << vint[0] << endl;
        // access the first element using front
        cout << "using front: " << vint.front() << endl;
        // access the first element using begin()
        cout << "using begin: " << *vint.begin() << endl;
    }

    vector<int> vint2;

    cout << "Trying to access the first element of the empty container: " << endl;
    // try to access the empty container
    cout << "using at: " << vint2.at(0) << endl;
    cout << "using []: " << vint2[0] << endl;
    cout << "using front: " << vint.front() << endl;
    cout << "using begin: " << *vint.begin() << endl;

    return 0;
}