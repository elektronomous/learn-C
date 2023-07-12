#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <iostream>
#include <string>

struct Sales_data {
    // new members: operations on Sales_data objects
    std::string isbn(/* Sales_data *const this */) const { // The purpose of that const is to modify the type of the implicit this pointer
        return bookNo;
        /* or you can also
        
        return this->bookNo;

            if you wonder 'this' is parameter that has type
        
        Sales_data *const
        
            you can't change the address of const pointer.
            now if you wonder why don't we make the Sales_data to be const
            in the 'this' data type, since we're doing is just return the
            data member of the object, you can see at the comment right after
            the "const {":
        
        const Sales_data *const this

            We can think of the body of isbn as if it were written as:
        
        std::string Sales_data::isbn(const Sales_data *const this) {
            return this->isbn;
        }

        */
        
    }     // define inside class, implicityly inline
    
    Sales_data& combine(const Sales_data &);        // define elsewhere
    double avg_price() const;                       // define elsewhere

    // data members are unchange from page 72
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);


// defininig the function named avg_price that is declared 
// in the scope of the Sales_data class.
double Sales_data::avg_price(void) const {
    if (units_sold)
        return revenue / units_sold;        // the revenue and units_sold are implicitly refering to
                                            // the members of Sales_data.
    
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
    /* 
    why *this ? not this ? 
    
    = The parameter of this is a pointer, to get the reference
      to actual object data type (Sales_data) you need to dereference
      the pointer first.
    */
}

/* 
    Both following functions are return references because the
    IO classes are types that cannot be copied.
    If you wonder why don't we return reference to const?
    because when reading and writing to the stream object (istream
    and ostream), we're modifying the value of the object.
*/
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
       << " " << item.avg_price() << endl;
    
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;       // copy data members from lhs into sum
    sum.combine(rhs);

    return sum;
}
#endif

