#include <iostream>
#include <deque>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    deque<Sales_data> dqSales_data;

    dqSales_data.emplace_front();         // use the Sales_data default constructor
    dqSales_data.emplace_front("ISBN-AAAA", 10, 500);     // use the Sales_data another constructor

    for (const Sales_data &sales: dqSales_data)
        print(cout, sales) << endl;
    cout << endl;

    return 0;
}