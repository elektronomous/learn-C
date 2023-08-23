#include <iostream>
#include <forward_list>

using namespace std;

/* Iterators, pointers, and references (including the off-the-end and
   the-before-beginning iterators) to a list or forward_list remain
   valid
*/

int main(void) {
    forward_list<int> flint {1,2,3};
    forward_list<int>::iterator start_point = flint.begin();
    forward_list<int>::iterator end_point = flint.end();
    forward_list<int>::iterator off_start_point = flint.before_begin();

    cout << "The address of each element: " << endl;
    for (const int &val: flint)
        cout << &val << " | " << val << endl;
    
    cout << "The address of start_point iterators: " << &(*start_point) << endl;
    cout << "The address of end_point iterators: " << &(*end_point) << endl;
    cout << "The address of the off_start_point iterators: " << &(*off_start_point) << endl;

    return 0;
}