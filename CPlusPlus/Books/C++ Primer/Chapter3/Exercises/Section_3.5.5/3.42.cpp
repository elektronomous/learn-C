#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main(void) {
    vector<int> vint {1,2,3,4,5,6,7};
    // get the size of vint, and save to the nArray
    const size_t nArray = vint.size();

    int arrFromVec[nArray];

    for (size_t n = 0; n < nArray; n++)
        arrFromVec[n] = vint[n];
    
    for (size_t n = 0; n < nArray; n++)
        cout << arrFromVec[n] << " ";
    cout << std::endl;


    return 0;
}