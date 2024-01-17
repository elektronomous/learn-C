#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};


    cout << "Before replace: " << endl;
    for_each(vint.cbegin(), vint.cend(), [](const int &v) { cout << v << " "; });
    cout << endl;

    // replace
    for_each(vint.begin(), vint.end(), [](int &v) { v = multiplies<int>()(v, 2); });

    cout << "After replace: " << endl;
    for_each(vint.cbegin(), vint.cend(), [](const int &v) { cout << v << " "; });
    cout << endl;


    return 0;
}