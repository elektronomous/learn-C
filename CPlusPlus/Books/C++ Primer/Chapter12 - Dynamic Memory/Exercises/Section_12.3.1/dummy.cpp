#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

/**/
map<int,set<size_t>> getVector() {
    return map<int,set<size_t>>{
        {1,{1,2,3,4,5}},
        {2,{2,3,4,5,6}}
    };
}

int getIndex(void) {
    return 1;
}

int main(void) {
    set<size_t> s = getVector()[1];

    for (const size_t &n: s)
        cout << n << endl;
    return 0;
}