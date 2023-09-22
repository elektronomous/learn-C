#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};

    // reset all vint element to zero
    fill(vint.begin(), vint.end(), 0);
    // set the half of the vint elements to be 10
    fill(vint.begin(), vint.begin() + (vint.size()/2), 10);

    return 0;
}

/*
Because fill writes to its given input sequence, so long as we pass a valid input
sequence, the writes will be safe
*/