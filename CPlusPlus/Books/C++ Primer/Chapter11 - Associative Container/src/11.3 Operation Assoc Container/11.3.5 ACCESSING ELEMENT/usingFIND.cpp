#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(void) {
    set<int> iset {0,1,2,3,4,5,6,7,8,9};
    map<int, int> mapint{{1,1}, {2,2}, {3,3}};

    iset.find(1);           // returns an iterator that refers to the element with key == 1
    iset.find(11);          // returns the iterator == iset.end()
    iset.count(1);          // returns 1
    iset.count(11);         // returns 0

    mapint.find(1);         // returns an iterator that refers to the element with key == 1
    mapint.find(4);         // returns an iterator == mapint.end()
    


}