#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(void) {
    string str {"muhammad faza, akbar"};
    vector<int> vint {1,2,3,4,5};

    cout << "Before sort: " << endl;
    for (const int &i: vint)
        cout << i << " ";
    cout << endl;

    cout << "Sorting descending: " << endl;
    sort(vint.rbegin(), vint.rend());

    cout << "After sorting: " << endl;
    for (const int &i: vint)
        cout << i << " ";
    cout << endl;

    string::reverse_iterator comma = find(str.rbegin(), str.rend(), ',');

    if (comma != str.rend())
        cout << string(comma.base(), str.end()) << endl;

    return 0;
}