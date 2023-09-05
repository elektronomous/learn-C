#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3};
    vector<int>::iterator begin_vint = vint.begin();

    while (begin_vint != vint.end()) {
        ++begin_vint;
        vint.insert(begin_vint, 42);
        ++begin_vint;
    }

    return 0;
}