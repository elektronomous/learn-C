#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void) {
    Sales_data book1, book2, book3;
    double priceBook1 = 0.0,
           priceBook2 = 0.0,
           priceBook3 = 0.0;

    // read FROM book1, book2, book3
    std::cin >> book1.bookNo
             >> book1.units_sold
             >> priceBook1
             >> book2.bookNo
             >> book2.units_sold
             >> priceBook2
             >> book3.bookNo
             >> book3.units_sold
             >> priceBook3;

    // calculate revenue of each of the book
    book1.revenue = book1.units_sold * priceBook1;
    book2.revenue = book2.units_sold * priceBook2;
    book3.revenue = book3.units_sold * priceBook3;

    // write the result
    std::cout << "Book1: " << std::endl
              << book1.bookNo << " "
              << book1.units_sold << " "
              << book1.revenue
              << std::endl;

    std::cout << "Book2: " << std::endl
              << book2.bookNo << " "
              << book2.units_sold << " "
              << book3.revenue
              << std::endl;

    std::cout << "Book3: " << std::endl
              << book3.bookNo << " "
              << book3.units_sold << " "
              << book3.revenue
              << std::endl;

    return 0;
}