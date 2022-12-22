#include <iostream>
#include "../../Sales_item.h"

int main(void) {
    Sales_item book1, book2, book3;

    // read FROM book1, book2, book3 
    std::cin >> book1 >> book2 >> book3;

    // write to standard output
    std::cout << "Book1: " << std::endl << book1 << std::endl;
    std::cout << "Book2: " << std::endl << book2 << std::endl;
    std::cout << "Book3: " << std::endl << book3 << std::endl;

    return 0;
}