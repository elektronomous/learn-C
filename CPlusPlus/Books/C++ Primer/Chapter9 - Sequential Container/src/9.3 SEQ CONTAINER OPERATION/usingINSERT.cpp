#include <vector>
#include <iostream>

using namespace std;

int main(void) { 
    vector<int> vint {1,2};
    vector<string> v {}
    vector<int>::iterator vintBegin = vint.begin();

    // insert front on vector is expensive operation
    // it's like doing push_front but on the vector
    vint.insert(vintBegin, {7,8,9});        // insert {7,8,9} just before vintBegin


    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    return 0;
}