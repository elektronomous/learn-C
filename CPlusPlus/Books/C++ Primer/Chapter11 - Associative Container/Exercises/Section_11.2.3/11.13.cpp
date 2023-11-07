#include <iostream>
#include <utility> // pairs
#include "Sales_data.hpp"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(void) {
    // (1)
    pair<int, int> pairInt {1,1};
    // (2)
    pair<int, int> pairInt2 = make_pair(1,1);
    // (3)
    pair<int, int> pairInt3;
}