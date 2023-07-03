#include <iostream>
#include <stdexcept>
#include "Sales_item.h"

using std::cin,
      std::cout,
      std::endl;

int main(void) {
    Sales_item item1, item2;

    while (cin >> item1 >> item2) {
        try {
            if (item1.isbn() != item2.isbn())
                throw std::runtime_error("Data must refer to the same ISBN.");
            else 
                cout << item1 + item2 << endl;
        } catch (std::runtime_error& err) {
            cout << err.what()
                 << "\nTry Again? Enter y or n: ";
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;              // break out of the while loop
        }
    }
}