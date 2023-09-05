#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {0,1,2,3,4,5,6};

    list<int>::iterator begin_iterator = lint.begin();

    while (begin_iterator != lint.end()) {
        if (*begin_iterator % 2) {
            begin_iterator = lint.insert(begin_iterator, *begin_iterator++);
        } else
            begin_iterator = lint.erase(begin_iterator);
    }
    
    return 0;
}