#include <iostream>
#include "../../Sales_item.h"

int main(void) {
    Sales_item book1, book2;

    // read the same ISBN of book1 and book2
    std::cin >> book1 >> book2;

    // show the result of their sum
    std::cout << book1 + book2 << std::endl;

    return 0;
}