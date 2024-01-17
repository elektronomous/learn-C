#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1234,2435,3242,212,4523,512};
    greater<int> greaterThan1024(1024);
    size_t greaterThan1024 = count_if(vint.begin(), vint.end(), greater<int>(1024));

    
}