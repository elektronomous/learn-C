#include <iostream>
#include <string>       // so we can use the bookNo in Sales_data.hpp
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data total, trans;
    double average = 0.0;

    if (read(cin, total)) {
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }else {
                average = total.revenue / total.units_sold;
                print(cout, total) << "\n";
                total = trans; 
            }
        }
        print(cout, total) << "\n";
    } else 
        cerr << "No data?!" << endl;

    return 0;
}