#include <iostream>
#include <string>
#include "../Sales_data.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void) {
    Sales_data book1, book2;
    int priceBook1 = 0, priceBook2 = 0;

    // read the same ISBN of book1 and book2
    cin >> book1.bookNo
        >> book1.units_sold
        >> priceBook1
        >> book2.bookNo
        >> book2.units_sold
        >> priceBook2;

    // calculate revenue of each of the books
    book1.revenue = book1.units_sold * priceBook1;
    book2.revenue = book2.units_sold * priceBook2;

    if (book1.bookNo == book2.bookNo) {
        cout << book1.bookNo << " "
             << book1.units_sold + book2.units_sold << " "
             << book1.revenue + book2.revenue
             << endl;
    } else {
        cout << book1.bookNo << " "
             << book1.units_sold << " "
             << book1.revenue
             << endl;
        cout << book2.bookNo << " "
             << book2.units_sold << " "
             << book2.revenue
             << endl;
    }

    return 0;

}