#include "Sales_item.h"
#include <iostream>

using std::cin,
      std::cerr,
      std::cout,
      std::endl;

int main(void) {
    Sales_item item1, item2;

    cin >> item1 >> item2;

    // first check that item1 and item2 represent the same book
    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
        return 0;   // indicate success
    } else {
        /* 
        cerr << "Data must refer to same ISBN." << endl;
        return -1;  // indicate failure 
        */
       throw std::runtime_error("Data must refer to same ISBN.");
    }
}