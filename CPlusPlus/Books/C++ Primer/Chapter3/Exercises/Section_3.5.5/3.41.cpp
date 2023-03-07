#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main(void) {
    int number_arr[] = {0,1,2,3,4,5,6,7,8,9};
    // initialize vector using array
    vector<int> vint(std::begin(number_arr), std::end(number_arr));

    cout << "After copy array to vector: ";
    for(int &val: vint) 
        cout << val << " ";
    cout << std::endl;

    return 0;
}