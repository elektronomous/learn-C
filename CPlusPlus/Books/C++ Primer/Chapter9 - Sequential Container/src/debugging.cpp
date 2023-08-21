#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,6,7,8};
    vector<int>::iterator firstIterator = vint.begin() + 2;
    vector<int>::iterator secondIterator = vint.begin() + 2;

    vint.erase(firstIterator, secondIterator);

    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;
}