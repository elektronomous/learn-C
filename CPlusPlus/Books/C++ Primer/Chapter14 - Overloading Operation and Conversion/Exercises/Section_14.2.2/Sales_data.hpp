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
    // 14.2 => overloaded operators
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);

    public:         // access specifier
    // constructors
        Sales_data() = default;
    /* 
        = We must define the default constructor, because we're going to define
          any other constructors. If we don't define this default constructor after
          defining other constructor, we aren't allowed to create object with no arguments.

                Sales_data total;       // error
                Sales_data tarns;       // error

        = By using this default, we're allowed to create an object with no arguments

                Sales_data total, trans;
    */
        explicit Sales_data(const std::string &s): bookNo(s) {}
        Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
        explicit Sales_data(std::istream &);          // we're defining this constructor outside this scope

        /* 
        = The explicit keyword is meaningful only on constructors that can be called with a single arg.
        = The explicit keyword is used only on the constructor declaration inside the class.
        */






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

        // 14.2 => overloaded operators
        std::istream& operator>>(Sales_data&);          // overloaded input operator
        std::ostream& operator<<(const Sales_data&);    // overloaded output operator

    private:
    // data members are unchange from page 72
    // in-class initializer is applied to class directly
    // like the 0 and 0.0
    // in case the of string class, it uses the in-class initializer of its class
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
    os << item.isbn() << "\t" << item.units_sold << "\t" << item.revenue
       << "\t" << item.avg_price();
    
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;       // copy data members from lhs into sum
    sum.combine(rhs);

    return sum;
}

// constructor definitions
Sales_data::Sales_data(std::istream &is) {
    read(is, *this);    // read will read a transaction from is into this object.
}

// 14.6
std::ostream& operator<<(std::ostream &os, const Sales_data &data) {
    os << data.isbn() << " " << data.units_sold << " "
       << data.revenue << " " << data.avg_price();

    return os;
}

// 14.9.txt
std::istream& operator>>(std::istream &is, Sales_data &data) {
    double price;
    std::string backup_bookNo = data.isbn();

    is >> data.bookNo >> data.units_sold >> price;

    if (is)
        data.revenue = data.units_sold * price;
    else
        data = Sales_data(backup_bookNo);       // reset the value if IO fail
    

    return is;
}
#endif