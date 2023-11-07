#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    vector<int> ivec {2,4,6,8,2,4,6,8};
    set<int> set2;

    // insert into set2
    set2.insert(ivec.cbegin(), ivec.cend());    // set 2 has four elements
    set2.insert({1,3,5,7,1,3,5,7});             // set 2 has 8 elements now

    return 0;
}