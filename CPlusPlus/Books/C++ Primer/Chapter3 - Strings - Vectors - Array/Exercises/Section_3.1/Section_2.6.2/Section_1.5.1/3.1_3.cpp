#include <iostream>
#include <string>
#include "../Sales_data.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    Sales_data book1, book2, book3, book4, books;
    int priceBook1 = 0, priceBook2 = 0,
        priceBook3 = 0, priceBook4 = 0;

    // read the same ISBN of book1 and book2
    cout << "Enter same ISBN, we accumulated different library with the same books." << endl
         << "Format input: (ISBN) (unit sold) (price)" << endl;

    cin >> book1.bookNo
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

    cout << books.bookNo << " " << books.units_sold << " " << books.revenue << endl;

    return 0;
}