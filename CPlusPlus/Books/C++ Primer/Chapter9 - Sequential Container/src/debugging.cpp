#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {};

    if (lint.begin() == lint.end())
        cout << "Same" << endl;
    
    list<int>::iterator toLint = lint.insert(lint.begin(), 2);
    
    if (lint.begin() != lint.end())
        cout << "Isn't same" << endl;
    
    cout << *toLint << endl;
    
    return 0;
}