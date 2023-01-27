#include <iostream>
#include "../../src/Sales_item.h"

int main(void) {
    Sales_item book1, book2, book3, book4;

    // read the same ISBN from book1, book2, book3, book4
    std::cin >> book1 >> book2 >> book3 >> book4;

    // show the result of the sum of 4 of them
    std::cout << book1 + book2 + book3 + book4 << std::endl;

    return 0;
}