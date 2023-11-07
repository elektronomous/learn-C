#include <iostream>
#include <set>
#include "Sales_data.hpp"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(void) {
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);
    multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::iterator firstBook = bookstore.begin();

    if (firstBook == bookstore.end())
        cout << "There's no book here listed." << endl;
    return 0;
}