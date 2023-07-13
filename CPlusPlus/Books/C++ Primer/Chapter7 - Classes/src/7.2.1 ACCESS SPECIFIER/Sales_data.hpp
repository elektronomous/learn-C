#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
#include <string>

class Sales_data {
    public:         // access specifier

    // Constructor:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p):
                   bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(const std::string &s): bookNo(s) { }
        Sales_data(std::isream&);
    
    // member functions:
        std::string isbn(void) const { return bookNo; }
        Sales_data &combine(const Sales_data &);
    
    private:
        double avg_price() const {
            return units_sold ? revenue / units_sold : 0;
        }

        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
#endif