#include <iostream>
#include <list>
#include <algorithm>    // using replace 

using namespace std;
/*
This algorithm takes four parameters: two iterators denoting the input range, and two values. It
replaces each element that is equal to the first value with the second
*/

int main(void) {
    list<int> lint {1,2,3,0,0,4,5,0,0,8,9,0,0,11};

    cout << "List numbers before replace: " << endl;
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    // replace 0 with 42
    replace(lint.begin(), lint.end(), 0, 42);

    cout << "List numbers after replace:" << endl;
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    return 0;
}