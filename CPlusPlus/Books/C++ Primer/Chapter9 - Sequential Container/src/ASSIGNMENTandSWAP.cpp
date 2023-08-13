#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    vector<int>  anotherVint {6,7,8,9,10};
    array<int, 5> arrInt {2,3,4};
    array<int, 5> anotherArrInt {3,4,5};

    // replace the contents of vint
    vint = anotherVint;
    // you can reassign the all the container except array
    vint = {1,2,3,4,5};
    // replace the arrInt using anotherArrInt
    arrInt = anotherArrInt;
    // arrInt = {1,2,3,4};      // you can't

}