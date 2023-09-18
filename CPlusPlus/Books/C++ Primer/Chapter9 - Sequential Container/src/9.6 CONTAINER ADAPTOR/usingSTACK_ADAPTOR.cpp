#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) { 
    /* 
        Each adaptor defines two constructors: the default constructor that creates an empty
        object, and a constructor that takes a container and initializes the adaptor by copying
        the given container
    */
    vector<int> vint {1,2,3,4,5};
    stack<int, vector<int>> stackVstrInt(vint); 

    cout << vint.at(0) << endl;
    cout << stackVstrInt.top() << endl;


    return 0;
}