#include <iostream>
#include <iterator>
#include "Sales_item.h"

using namespace std;

int main(void) {
    istream_iterator<Sales_item> istreamSales(cin), eof_istreamSales;
    ostream_iterator<Sales_item> ostreamSales(cout, "\n");

    // store the first transaction and read the next record
    Sales_item sum = *istreamSales;

    while (istreamSales != eof_istreamSales) {
        // if the current transaction (which is stored in istreamSales) has the same ISBN
        if (istreamSales->isbn() == sum.isbn())
            sum += *istreamSales++;     // add it to sum
        else {
            ostreamSales = sum;         // write the current sum
            sum = *istreamSales++;      // read the next transaction
        }
    }
    ostreamSales = sum;     // remember to print the last set of records

    return 0;
}