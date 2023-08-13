#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4};
    vector<int> vint2 {1,2,3,4,5,6,7,8,9,10};

    vint = vint2;

    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;
}