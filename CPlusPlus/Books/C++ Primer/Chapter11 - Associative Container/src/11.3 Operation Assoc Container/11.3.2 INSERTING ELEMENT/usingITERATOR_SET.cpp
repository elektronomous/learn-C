#include <iostream>
#include <set>

using namespace std;

int main(void) {
    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int>::iterator set_it = iset.begin();

    if (set_it != iset.end()) {
       // *set_it = 42;           Keys in set are read-only
       cout << *set_it << endl;     // OK: can read the key
    }

    return 0;
}