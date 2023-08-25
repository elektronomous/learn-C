#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,6};

    // exactly same like vint.clear()
    while (!vint.empty())
        vint.pop_back();        // remove elements from back
    
    if (vint.empty())
        cout << "We've clear the vint elements" << endl;


    return 0;
}