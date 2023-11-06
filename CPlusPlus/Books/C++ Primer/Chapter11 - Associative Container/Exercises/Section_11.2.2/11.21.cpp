#include <iostream>
#include <set>
#include "Sales_data.hpp"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();

}

int main(void) {
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookStore(compareIsbn);
                         /* 
                            If you wonder why there's no name on the pointer to the function
                            right there? because it's just a type read NOTE.txt
                            on 11.2 Overview Associative Container
                         */
    return 0;
}