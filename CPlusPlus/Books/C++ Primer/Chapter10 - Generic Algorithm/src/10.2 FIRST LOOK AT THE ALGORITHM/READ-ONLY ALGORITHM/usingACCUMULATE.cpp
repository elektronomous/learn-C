#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    vector<string> name {"muhammad","faza","akbar"};

    // sum the elements in vec starting the summation with the value 0
    int sum = accumulate(vint.cbegin(), vint.cend(), 0);
    string fullName = accumulate(name.cbegin(), name.cend(), string("-"));

    cout << "The result: " << sum << endl;
    cout << "The fullname: " << fullName << endl;

    return 0;
}