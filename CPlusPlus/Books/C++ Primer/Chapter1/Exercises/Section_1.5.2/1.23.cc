#include <iostream>
#include "../../Sales_item.h"

int main(void) {
    Sales_item currBook, book;

    if (std::cin >> currBook) {
        int cnt = 1;                // the current books we set 1, because
                                    // the current books isbn occurs 1 times
        while (std::cin >> book) {
            if (currBook.isbn() == book.isbn()) {
                cnt++;
            } else {
                std::cout << "There are " << cnt << " ISBNs of " 
                          << currBook.isbn() << std::endl;
                currBook = book;
            }
        }
        std::cout << "There are " << cnt << " ISBNs of "
                  << currBook.isbn() << std::endl;
    }

    return 0;
}