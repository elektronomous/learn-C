#include <iostream>
#include <string>
#include "../Sales_data.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    Sales_data currBook, book;

    if (cin >> currBook.bookNo) {
        int cnt = 1;        // we set the books occurent to be 1, because
                            // the isbn of the books occurs 1 time

        while (cin >> book.bookNo) {
            if (currBook.bookNo == book.bookNo) {
                cnt++;
            } else {
                cout << "There are " << cnt << (cnt > 1 ? " ISBNs of ": " ISBN of " )
                     << currBook.bookNo << endl;
                currBook = book;
                cnt = 1;
            }
        }
        cout << "There are " << cnt 
             << (cnt > 1 ? " ISBNs of ": " ISBN of " )
             << currBook.bookNo 
             << endl;
    }

    return 0;
}