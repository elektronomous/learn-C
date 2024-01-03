#include <iostream>
#include <algorithm>
#include <vector>
#include "HasPtr_value.hpp"

using namespace std;

int main(void) {
    vector<HasPtr> vHasPtr {{"faza"},{"anggun"},{"akbar"}};
    
    cout << "Before sort: " << endl;
    for_each(vHasPtr.begin(), vHasPtr.end(), [](HasPtr &h) { cout << h.getString() << " "; });
    cout << endl;

    // sort the vector of vHasPtr
    sort(vHasPtr.begin(), vHasPtr.end());

    for_each(vHasPtr.begin(), vHasPtr.end(), [](HasPtr &h) { cout << h.getString() << " "; });

    return 0;

}