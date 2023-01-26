#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main(void) {
    int sum = 0, val = 50;

    while(val <= 100) {
        sum += val;
        ++val;
    }

    cout << "Sum of 50 to 100 inclusive is "
         << sum << endl;

    return 0;
}
