#include <iostream>
#include <forward_list>

using namespace std;

int main(void) {
    forward_list<int> flint {1,2,3,4,5,6,7,8,9};
    forward_list<int>::iterator flintPrev = flint.before_begin();
    forward_list<int>::iterator flintCurr = flint.begin();

    while (flintCurr != flint.end()) {
        if (*flintCurr % 2)
            flintCurr = flint.erase_after(flintPrev);
        else {
            flintPrev = flintCurr;
            flintCurr++;
        }
    }

    cout << "The forward_list contains: ";
    for (const int &val: flint)
        cout << val << " ";
    cout << endl;

    return 0;
}