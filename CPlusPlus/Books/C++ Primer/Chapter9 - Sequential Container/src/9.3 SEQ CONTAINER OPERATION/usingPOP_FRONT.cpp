#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5};

    // exactly like lint.clear()
    while (!lint.empty())
        lint.pop_front();       // remove elements beginning from the first element
    
    if (lint.empty())
        cout << "We've clear the list of ints" << endl;
    
    return 0;
}