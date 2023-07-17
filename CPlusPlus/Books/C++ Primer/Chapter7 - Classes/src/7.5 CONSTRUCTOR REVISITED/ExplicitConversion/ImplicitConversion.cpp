#include <iostream>
#include <string>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    Sales_data item("9-999-99999-9", 10, 50);
    /*
        Sales_data(std::istream&);
        Sales_data(const std::string &s);

    = Both constructor define implicit conversions from those type to Sales_data.
      That is we can use a string or istream where an object of type Sales_data is
      expected.
    */
    string null_book = "9-999-99999-9";
    
    // Sales_data::combine(const Sales_data &);
  /* 
    we prevent the use of constructor in a context that requires an implicit 
    conversion by declaring the constructor(look at the Sales_data.hpp). 

        
        Sales_data item1(null_book)         => OK: direct initialization

    One context in which implicit conversions happen is when we use the copy form of
    initialization(with an =): 
    So the following code will be error. If you remove the explicit keyword, it'll
    be normal:

        Sales_data item1 = null_book        => ERROR: cannot use the copy form of initialization with an explicit constructor
    
        item.combine(null_book);             comppiler automatically convert the string null_book
                                           to temporary Sales_data object. We can pass this temporary
                                           because the parameter is const.
        
    The compiler will automatically apply only one class-type conversion:
    (1) convert "9-999-99999-9" to string
    (2) convert that temporary string to Sales_data.
    
        item.combine("9-999-99999-9");              => error: compiler will automatically apply only one class-type
                                                          conversion.
        item.combine(string("9-999-99999-9"));      => OK: Explicit conversion to string, implicit conversion to Sales_data
        item.combine(Sales_data("9-999-99999-9"))   => OK: implicity conversion to string, explicit conversion to Sales_data
    */


    print(cout, item) << "\n";

    return 0;    
}