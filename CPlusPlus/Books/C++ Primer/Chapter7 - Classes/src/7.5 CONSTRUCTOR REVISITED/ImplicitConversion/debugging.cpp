#include <iostream>
#include <string>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data i("aaa", 10, 50);
    string s("aaa");

    i.combine(s);

    return 0;
}