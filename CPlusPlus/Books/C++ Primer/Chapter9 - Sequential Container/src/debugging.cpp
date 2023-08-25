#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5};
    list<int>::iterator middleIterator = lint.begin();
    middleIterator++;
    middleIterator++;

    list<int>::iterator afterDeleteIterator = lint.insert(middleIterator, 10);

    cout << *middleIterator << endl;
    cout << *afterDeleteIterator << endl;

    cout << "lint contains: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;
    return 0;
}