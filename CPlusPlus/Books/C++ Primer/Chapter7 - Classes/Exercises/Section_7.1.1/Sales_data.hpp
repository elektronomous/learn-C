#ifndef SALES_DATA_H
#define SALES_DATA_H

class Sales_data {
    public:
    // in-class initializer is applied to class directly
    // like the 0 and 0.0
    // in case the of string class, it uses the in-class initializer of its class
        std::string bookNo;             // include the string header in main program, not here
        unsigned units_sold = 0;
        double revenue = 0.0;
};

#endif