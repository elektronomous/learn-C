#include <iostream>
#include <string>

struct Sales_data { 
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void) {
    Sales_data book1, book2, book3, book4, books;
    int priceBook1 = 0, priceBook2 = 0,
        priceBook3 = 0, priceBook4 = 0;

    // read the same ISBN of book1 and book2
    std::cout << "Enter same ISBN, we accumulated different library with the same books." << std::endl
              << "Format input: (ISBN) (unit sold) (price)" << std::endl;

    std::cin >> book1.bookNo
             >> book1.units_sold
             >> priceBook1
             >> book2.bookNo
             >> book2.units_sold
             >> priceBook2
             >> book3.bookNo
             >> book3.units_sold
             >> priceBook3
             >> book4.bookNo
             >> book4.units_sold;


    // calculate revenue of each of the books
    books.bookNo = book1.bookNo;
    books.units_sold = book1.units_sold + book2.units_sold + book3.units_sold +
                       book4.units_sold;
    books.revenue = (priceBook1 * book1.units_sold) + (priceBook2 * book2.units_sold) +
                    (priceBook3 * book3.units_sold) + (priceBook4 * book4.units_sold);

    std::cout << books.bookNo << " " << books.units_sold << " " << books.revenue << std::endl;

    return 0;
}