#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vints {1023, 100233, 9952, 34214, 555};
    greater<int> greaterThan1024;

    int valuesGreaterThan1024 = count_if(vints.begin(), vints.end(), bind(greaterThan1024, placeholders::_1, 1024));

    cout << "How many values that are greater than 1024 inside the vints: " << endl;
    cout << valuesGreaterThan1024 << endl;

    return 0;
}