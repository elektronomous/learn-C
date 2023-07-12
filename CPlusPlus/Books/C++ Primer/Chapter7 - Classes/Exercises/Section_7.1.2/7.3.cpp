#include <iostream>
#include <string>       // so we can use the bookNo in Sales_data.hpp
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data total, trans;
    double price = 0.0, average = 0.0;

    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = price * total.units_sold;

        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = price * trans.units_sold;

            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }else {
                average = total.revenue / total.units_sold;
                cout << fixed << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << average << endl;
                total = trans; 
            }
        }
        cout << fixed << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << average << endl;
    } else 
        cerr << "No data?!" << endl;

    return 0;
}