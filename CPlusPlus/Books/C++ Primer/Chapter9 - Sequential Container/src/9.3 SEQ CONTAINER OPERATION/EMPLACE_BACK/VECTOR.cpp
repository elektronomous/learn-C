#include <iostream>
#include <vector>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    vector<Sales_data> vSales_data;

    vSales_data.emplace_back();         // use the Sales_data default constructor
    vSales_data.emplace_back("ISBN-AAAA", 10, 500);     // use the Sales_data another constructor

    for (const Sales_data &sales: vSales_data)
        print(cout, sales) << endl;
    cout << endl;

    return 0;
}