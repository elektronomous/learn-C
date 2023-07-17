#include <iostream>
#include <vector>
#include "7.43.hpp"

using namespace std;

int main(void) {
    vector<NoDefault> vec(10);

    cout << vec[0].getData() << endl;
    
    return 0;
}