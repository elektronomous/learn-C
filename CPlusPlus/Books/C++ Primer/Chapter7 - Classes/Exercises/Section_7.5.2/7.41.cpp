#include <iostream>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data sdata(cin);

    print(cout, sdata) << endl;
    return 0;
}
