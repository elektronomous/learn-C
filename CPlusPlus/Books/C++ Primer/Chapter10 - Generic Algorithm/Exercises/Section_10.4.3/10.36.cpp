#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5,6,7,0,8,9};

    list<int>::reverse_iterator getZero = find(lint.rbegin(), lint.rend(), 0);

    if (getZero != lint.rend())
        cout << "Find the value " << *getZero << endl;

    return 0;
}