#include <iostream>
#include <forward_list>

using namespace std;

int main(void) {
    forward_list<int> flint {0,1,2,3,4,5,6};
    forward_list<int>::iterator begin_flint = flint.begin();
    forward_list<int>::iterator bbegin_flint = flint.before_begin();

    while (begin_flint != flint.end()) {
        if (*begin_flint % 2) {
            begin_flint = flint.insert_after(begin_flint, *begin_flint);
            begin_flint++;
            bbegin_flint++;
        } else {
            begin_flint = flint.erase_after(bbegin_flint);
            bbegin_flint = begin_flint;
        }

    }

    // display the result
    cout << "The contents of forward_list: ";
    for (const int &val: flint)
        cout << val << " ";
    cout << endl;

    return 0;
}