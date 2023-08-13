#include <iostream>
#include <vector>

using namespace std;

bool vecCompare(const vector<int> &v1, const vector<int> &v2) {
    return v1 == v2;
}

int main(void) {
    vector<int> vint {1,2,3};
    vector<int> vint2 {1,2,3,4};

    if (vecCompare(vint, vint2))
        cout << "The vector is same" << endl;
    else
        cout << "The vector is different" << endl;

    return 0;
}