#include <iostream>
#include <vector>
#include <list>

int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

using namespace std;

int main(void) {
    vector<int> vint;
    list<int> lint;
    
    for (int *firstTo_ia = begin(ia); firstTo_ia != end(ia); firstTo_ia++) {
        vint.push_back(*firstTo_ia);
        lint.push_back(*firstTo_ia);
    }

    // erase the odd values from lint
    for (list<int>::iterator lintBegin = lint.begin(); lintBegin != lint.end(); lintBegin++)
        if (*lintBegin % 2 == 1)
            lintBegin = lint.erase(lintBegin); 

    // erase the even values from vector
    for (vector<int>::iterator vintBegin = vint.begin(); vintBegin != vint.end(); vintBegin++)
        if (*vintBegin % 2 == 0)
            vintBegin = vint.erase(vintBegin);
    
    /* Both of the iterator we assign back. remember when you remove/erase an element
       inside a loop iteration, the iterator will be invalidate which means the iterator
       doesn't longer point to the next element following the removed element.
    */
    
    // what's left in the list
    cout << "The list contains: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    // what's left in the vector
    cout << "The vector contains: ";
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;
}