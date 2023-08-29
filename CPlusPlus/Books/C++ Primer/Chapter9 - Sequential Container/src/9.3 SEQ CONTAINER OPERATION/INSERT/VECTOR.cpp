#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    // insert even value to odd value
    vector<int> oddVals {1,3};

    // display before insert
    cout << "odd values contain: " << endl;
    for (const int &val: oddVals)
        cout << val << " ";
    cout << endl;

    // insert
    vector<int>::iterator middleOddVals = oddVals.begin() + 1;
    vector<int>::iterator tofirstElementInserted = oddVals.insert(middleOddVals, {2,4,6});

    cout << "The first element inserted: " << *tofirstElementInserted << endl;
    /*
        2
    */

    // display after insert
    cout << "after insert: " << endl;
    for (const int &val: oddVals)
        cout << val << " ";
    cout << endl;
    /*
        1 2 4 6 3
    */

    return 0;
}