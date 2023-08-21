#include <iostream>
#include <forward_list>

using namespace std;

int main(void) {
    forward_list<int> flint {1,2,3,4,5,6,7,8};

    forward_list<int>::iterator prevBegin = flint.before_begin();   // denotes element "off the start" of flint
    forward_list<int>::iterator flintBegin = flint.begin();              // denotes the first element of flint

    while (flintBegin != flint.end()) {
        if (*flintBegin % 2)
            flintBegin = flint.erase_after(prevBegin);      // erase it and move flintBegin
        else {
            prevBegin = flintBegin;         // move the iterators to the next
            flintBegin++;
        }
    }
}