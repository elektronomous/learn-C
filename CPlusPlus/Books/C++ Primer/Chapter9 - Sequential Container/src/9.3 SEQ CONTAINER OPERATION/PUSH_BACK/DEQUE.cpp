#include <iostream>
#include <deque>

using namespace std;

int main(void) { 
    deque<int> deqint {1,2,3};
    
    // display before push_back
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /* 
        1 2 3 
    */

    // copy 5 and add to the back of the deqint
    deqint.push_back(5);
    
    // display after push_back
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;
    /*
        1 2 3 5
    */

    return 0;
}