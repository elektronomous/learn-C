#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    // if you want to adapt the vector to the stack adaptor:
    stack<int, vector<int>> stackVstrInt(vint);
    stack<int> stackInt;

    cout << vint.at(0) << endl;
    cout << stackVstrInt.top() << endl;

    cout << "Stack of integers: " << endl;
    for (const int &val: vint)
        stackInt.push(val);
    
    while (!stackInt.empty()) {
        // print the last value
        cout << stackInt.top() << endl;
        // remove the last value
        stackInt.pop();
    }


    return 0;
}