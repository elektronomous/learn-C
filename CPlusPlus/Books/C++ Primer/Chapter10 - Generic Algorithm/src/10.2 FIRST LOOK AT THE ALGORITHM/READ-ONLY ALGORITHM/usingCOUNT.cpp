#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,2,1,2,5,2,1,2,3,3,2,1,5,5,2,1};
    int val = 5;
    // how many value is in the vint
    int howManyFive = count(vint.cbegin(), vint.cend(), val);

    cout << val << " is appear " << howManyFive << " times" << endl;

    return 0;
}