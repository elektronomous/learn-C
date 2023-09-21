#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <numeric>


using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    array<int, 5> arrInt {1,2,3,4,5};
    string str = "a value";

    int val = 42;
    char chr = 'v';
    
    // look value inside the vector
    vector<int>::const_iterator itFoundValue = find(vint.cbegin(), vint.cend(), val);
    cout << "the value you've searched in vector: " 
         << (itFoundValue == vint.cend() ? " is not present": " is present")
         << endl;
    
    // look value inside the string
    string::const_iterator itFoundString = find(str.cbegin(), str.cend(), chr);
    cout << "The value you've search in string: "
         << (itFoundString == str.cend() ? " is not present": " is present")
         << endl;

    // look value inside the array
    array<int, 5>::const_iterator itFoundArray = find(cbegin(arrInt), cend(arrInt), val);
    cout << "The value you've search in array: "
         << (itFoundArray == arrInt.cend() ? " is not present": " is present")
         << endl;

    return 0;
}