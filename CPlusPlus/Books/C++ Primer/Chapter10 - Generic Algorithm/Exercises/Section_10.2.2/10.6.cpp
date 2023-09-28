#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vint {1,1,1,1,1};

    cout << "Vint before replace: " << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    cout << "Vint after replace: " << endl;
    fill_n(vint.begin(), vint.size(), 0);
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;
}