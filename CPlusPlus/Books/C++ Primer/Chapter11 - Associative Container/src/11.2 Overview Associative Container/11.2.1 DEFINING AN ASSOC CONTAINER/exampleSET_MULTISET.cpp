#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
    // define a vector with 20 elements, holding two copies of each number from 0 to 9
    vector<int> ivec;
    for(vector<int>::size_type i = 0; i != 10; i++) {
        ivec.push_back(i);
        ivec.push_back(i);      // duplicate copies of each number
    }

    // iset holds unique elements from ivec; miset holds all 20 elements
    set<int> iset(ivec.begin(), ivec.end());
    multiset<int> miset(ivec.begin(), ivec.end());

    cout << ivec.size() << endl;        // prints 20
    cout << iset.size() << endl;        // prints 10
    cout << miset.size() << endl;       // prints 20

    return 0;
}