#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data {

    public:
    // in-class initializer is applied to class directly
    // like the 0 and 0.0
    // in case the of string class, it uses the in-class initializer of its class
        std::string bookNo;             // include the string header in main program, not here
        unsigned units_sold = 0;
        double revenue = 0.0;

        Sales_data &combine(const Sales_data &);
        
        // 7.2
        std::string isbn(void) const {
            return bookNo;
        }
};


// 7.2
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

// 7.6
Sales_data sum(const Sales_data &item1, const Sales_data &item2) {
    Sales_data total = item1;       // copy the member data of item1;
    total.combine(item2);

    return total;
}

// 7.6
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;

    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}

// 7.6
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;

    return os;
}

#endif