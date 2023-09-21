#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};

    int total = accumulate(vint.cbegin(), vint.cend(), 0);

    cout << "The total of vint: " << total << endl;

    return 0;
}