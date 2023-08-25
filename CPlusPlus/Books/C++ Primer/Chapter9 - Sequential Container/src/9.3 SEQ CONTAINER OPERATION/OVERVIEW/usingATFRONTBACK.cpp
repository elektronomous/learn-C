#include <iostream>
#include <vector>

using namespace std;

void debug(const vector<int> &v) {
    for (const int &val: v)
        cout << val << " ";
    cout << endl;
}

int main(void) {
    // front, back, at return references.
    vector<int> vint {1,2,3,4,5};
    
    if (!vint.empty()) {
        // change the first element to 9
        vint.front() = 9;    
        cout << "After change the first element to 9: " << endl;
        debug(vint);

        // change the last element to 50
        int &last = vint.back();
        last = 50;
        cout << "After change the last element to 50: " << endl;
        debug(vint);
    }

    return 0;
}