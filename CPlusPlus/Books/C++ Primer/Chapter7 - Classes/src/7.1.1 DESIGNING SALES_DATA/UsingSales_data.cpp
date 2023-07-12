#include <iostream>
#include <string>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data total;

    cout << "Enter book number: ";
    cin >> total.bookNo;

    cout << total.isbn() << "\n";
    // when calling isbn(), the this keyword is implicitly initialized
    // with the address of the object(total)
    // It is as if the compiler rewrites this call as:
    //      
    //      Sales_data::isbn(&total);
    
    return 0;
}