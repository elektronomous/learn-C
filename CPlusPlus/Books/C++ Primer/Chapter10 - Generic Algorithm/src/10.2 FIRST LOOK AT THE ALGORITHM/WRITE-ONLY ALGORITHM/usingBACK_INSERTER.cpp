#include <iostream>
#include <vector>
#include <iterator>     // using back_inserter
using namespace std;


/* 
back_inserter takes a reference to a container and returns an insert
iterator bound to that container.

*/

int main(void) {
    vector<int> vint {1,2,3,4,5};
    back_insert_iterator<vector<int>> itVint = back_inserter(vint);

    *itVint = 10;

    cout << "Value after inserted in vint: " << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    /* 
    We frequently use back_inserter to create an iterator to use as the
    destination of an algorithm.
    */

   fill_n(back_inserter(vint), 7, 9);
   cout << "Value after using algorithm fill_n: " << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;


    return 0;
}