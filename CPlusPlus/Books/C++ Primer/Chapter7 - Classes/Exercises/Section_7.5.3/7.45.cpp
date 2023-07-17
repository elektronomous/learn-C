#include <iostream>
#include <vector>
#include "7.43.hpp"

using namespace std;

int main(void) {
    vector<Cclass> vec(10);

    cout << vec[0].getObj().getData() << endl;
    
    return 0;
}