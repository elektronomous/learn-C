#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,6};

    // always call vint in not empty state
    if (!vint.empty()) {
        // val and val2 are copies of the valeu of the first element in vint
        int val = *vint.begin(), val2 = vint.front();
        // val3 and val4 are copies of the of the last element in vint
        vector<int>::iterator last = vint.end();
        int val3 = *(--last);       // you can't decrement the forward_list iterators
        int val4 = vint.back();     // not supported by forward_list
    }

    return 0;
}