#include <iostream>
#include <string>

struct Sales_data { 
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void) {
    Sales_data book1, book2;
    int priceBook1 = 0, priceBook2 = 0;

    // read the same ISBN of book1 and book2
    std::cin >> book1.bookNo
             >> book1.units_sold
             >> priceBook1
             >> book2.bookNo
             >> book2.units_sold
             >> priceBook2;

    // calculate revenue of each of the books
    book1.revenue = book1.units_sold * priceBook1;
    book2.revenue = book2.units_sold * priceBook2;

    if (book1.bookNo == book2.bookNo) {
        std::cout << book1.bookNo << " "
                  << book1.units_sold + book2.units_sold << " "
                  << book1.revenue + book2.revenue
                  << std::endl;
    } else {
        std::cout << book1.bookNo << " "
                  << book1.units_sold << " "
                  << book1.revenue
                  << std::endl;
        std::cout << book2.bookNo << " "
                  << book2.units_sold << " "
                  << book2.revenue
                  << std::endl;
    }

    return 0;

}