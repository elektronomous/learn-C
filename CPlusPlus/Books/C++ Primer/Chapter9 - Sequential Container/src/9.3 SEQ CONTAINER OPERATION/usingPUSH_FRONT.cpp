#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void) {
    list<int> lint;
    vector<int> vint {1,2,3,4,5};

    for (const int &val: vint)
        lint.push_front(val);
    
    // cout lint
    cout << "Lint: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    return 0;
}
