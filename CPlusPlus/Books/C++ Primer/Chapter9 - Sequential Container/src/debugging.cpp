#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4};
    vector<int>::iterator toVint = vint.begin() + 2;

    cout << *toVint << endl;

    return 0;
}