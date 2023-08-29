#include <iostream>
#include <vector>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    vector<Sales_data> vSales_data;
    vector<Sales_data>::iterator vSales_begin = vSales_data.begin();

    // vSales_data.emplace(vSales_begin, "");       you can't use default constructor
    vSales_data.emplace(vSales_begin, "ISBN-AAAA", 50, 20);

    for (const Sales_data &sales: vSales_data)
        print(cout, sales) << endl;


    return 0;
}