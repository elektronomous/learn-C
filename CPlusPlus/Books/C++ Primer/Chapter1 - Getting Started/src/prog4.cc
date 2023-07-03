// READ AND WRITE Sales_item object
#include <iostream>
#include "Sales_item.h"

int main(void) {
    Sales_item book;

    // read ISBN, number of copies sold and sales_price
    std::cin >> book;

    // write ISBN, number of copies sold, total revenue and average price
    std::cout << book << std::endl;

    return 0;
}