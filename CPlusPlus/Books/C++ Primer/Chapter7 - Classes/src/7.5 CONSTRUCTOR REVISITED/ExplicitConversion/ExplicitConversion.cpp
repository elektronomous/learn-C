#include <iostream>
#include <string>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data item("ABC", 5, 100);
    string null_book("ABC");

    // use constructor explicitly to force conversion:
    item.combine(Sales_data(null_book));
    /*           ^^^^^^^^^^^^^^^^^^^^^ => This call constructs a temporary Sales_data object using 
                                        the Sales_data constructor that takes a string.
     or
          item.combine(static_cast<Sales_data>(cin))
                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ => static_cast uses the istream constructor to construct
                                                       a temporary Sales_data object.
    
    */

    print(cout, item);

    return 0;
}