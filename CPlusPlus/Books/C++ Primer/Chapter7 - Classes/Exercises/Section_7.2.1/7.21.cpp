#include <iostream>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data item1("01234"),
               item2("01234", 100, 500),
               item3;
    
    if (read(cin, item3))
        if (item1.isbn() == item3.isbn())
            item1.combine(item3);
    
    if (item1.isbn() == item2.isbn())
        item1.combine(item2);

    print(cout, item1) << "\n";

    return 0;
}