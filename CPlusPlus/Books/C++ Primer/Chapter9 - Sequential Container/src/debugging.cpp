#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4};
    vector<int>::iterator toVint = vint.begin() + 2;
    // before insert a value
    cout << "toVint after inserted value before it: " << *toVint << endl;

    // if i insert value on the iter, is iter would be invalidated?
    vint.insert(toVint, {5,6});

    cout << "toVint after inserted value before it: " << *toVint << endl;

    return 0;
}