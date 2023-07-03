#include <iostream>
#include "../../Sales_item.h"

int main(void) {
    Sales_item currBook, book;

    if (std::cin >> currBook) {
        while (std::cin >> book) {
            if (currBook.isbn() == book.isbn()) {
                currBook += book;
            } else {
                std::cout << currBook << std::endl;
                currBook = book;
            }
        }
        std::cout << currBook << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return EOF;
    }

    return 0;
}