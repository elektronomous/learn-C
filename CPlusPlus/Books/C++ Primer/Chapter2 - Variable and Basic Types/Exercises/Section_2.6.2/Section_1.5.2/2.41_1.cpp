#include <iostream>
#include <string>

struct Sales_data { 
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void) {
    Sales_data currBook, book;

    if (std::cin >> currBook.bookNo) {
        int cnt = 1;        // we set the books occurent to be 1, because
                            // the isbn of the books occurs 1 time

        while (std::cin >> book.bookNo) {
            if (currBook.bookNo == book.bookNo) {
                cnt++;
            } else {
                std::cout << "There are " << cnt << (cnt > 1 ? " ISBNs of ": " ISBN of " )
                          << currBook.bookNo << std::endl;
                currBook = book;
                cnt = 1;
            }
        }
        std::cout << "There are " << cnt << (cnt > 1 ? " ISBNs of ": " ISBN of " )
                          << currBook.bookNo << std::endl;
    }

    return 0;
}