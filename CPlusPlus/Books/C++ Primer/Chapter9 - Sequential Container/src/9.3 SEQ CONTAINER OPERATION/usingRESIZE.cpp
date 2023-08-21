#include <iostream>
#include <vector>

// resize only use in all containers except arrays
using namespace std;

int main(void) {
    vector<int> vint(10, 42);       // initialize ten elements, each value is 42
    vint.resize(15);                // adds five elements of value 0 to the back of vint
    vint.resize(25, -1);            // adds ten elements of value -1 to the back of vint
    vint.resize(5);                 // erases 20 elements from the back of vint
    
}