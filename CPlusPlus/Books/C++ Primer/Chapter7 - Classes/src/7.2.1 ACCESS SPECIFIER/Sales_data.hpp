#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
#include <string>

class Sales_data {
    // a class makes a function its friend by including a declaration
    // for that function preceded by the keyword "friend":
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);

    public:         // access specifier

    // Constructor:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p):
                   bookNo(s), units_sold(n), revenue(p*n) { }
        Sales_data(const std::string &s): bookNo(s) { }
        Sales_data(std::istream&);
    
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

// compiler allow you to declare these function only once
// in a friend declaration, but it's good idea/choice to 
// make seperate declaration like this:
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

#endif