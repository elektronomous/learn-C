// ADDING Sales_item

#include <iostream>
#include "Sales_item.h"

int main(void) {
    Sales_item item1, item2;

    // read ISBN, number of copies sold and sales price of each item
    std::cin >> item1 >> item2;
    // show their result sum
    std::cout << item1 + item2 << std::endl;

    return 0;
}

/*
RESULT =>

ABC 20 50.00
ABC 20 10
ABC 40 1200 30


*/