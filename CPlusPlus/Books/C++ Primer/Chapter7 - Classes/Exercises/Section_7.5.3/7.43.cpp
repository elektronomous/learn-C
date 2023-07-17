#include <iostream>
#include "7.43.hpp"

using namespace std;

int main(void) {
    Cclass myObj(10);

    cout << myObj.getObj().getData() << endl;

    return 0;
}