#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

int main(void) {
    vector<int> vint;
    int input = 0;

    // prompt user to enter values
    while(cin >> input) {
        // add element and initialize the element using the input value
        vint.push_back(input);
    }

    cout << "You input value: ";
    for (int &val : vint) 
        cout << val << " ";
    cout << endl;

    return 0;
}