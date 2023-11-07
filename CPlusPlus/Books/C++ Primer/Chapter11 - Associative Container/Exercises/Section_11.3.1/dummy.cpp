#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    
    multiset<string> c {"faza","akbar", "Muhammad"};
    vector<string> v;
    
    copy(v.begin(), v.end(), inserter(c, c.end()));
    // copy(v.begin(), v.end(), back_inserter(c));
    copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));

    return 0;
}