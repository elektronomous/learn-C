#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int val = 10;

    while (val >= 0) {
        cout << "The val: " << val
             << endl;
        --val;
    }

    return 0;
}