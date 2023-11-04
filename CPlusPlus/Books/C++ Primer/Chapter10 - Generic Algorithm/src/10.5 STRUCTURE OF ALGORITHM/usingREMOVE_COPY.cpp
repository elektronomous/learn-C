#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
    vector<int> vint {0,1,2,3,4,5,6,7,8,9};
    vector<int> outputVector;
    ostream_iterator<int> writeInt(cout, " ");

    cout << "Before remove: " << endl;
    copy(vint.begin(), vint.end(), writeInt);
    cout << endl;

    cout << "Removing.. " << endl;
    // remove even value from the element 1 to 5
    remove_if(vint.begin(), vint.begin() + 5, [](const int &i) { return i % 2;});

    cout << "After remove: " << endl;
    for_each(vint.begin(), vint.end(), [](const int &i) { cout << i << " ";});

    cout << "Show only even value: " << endl;
    // remove odd element from 5 to 10, and then put the result to output stream
    remove_copy_if(vint.begin() + 5, vint.end(), writeInt, [](const int &i) { return i %2;});

    return 0;
}