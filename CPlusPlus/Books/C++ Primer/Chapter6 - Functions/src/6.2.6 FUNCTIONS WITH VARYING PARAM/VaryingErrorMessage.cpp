#include <iostream>
#include <initializer_list>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::initializer_list,
      std::string;

void error_msg(initializer_list<string> il) {
    for (const string *beg = il.begin(); beg != il.end(); beg++)
        cout << *beg << " ";
    /* 
    for (const string *errMsg: il)
        cout << errMsg <<  " ";
    */
   
    cout << "\n";
}

int main(void) {
    // this is for example
    string expected = "true",
         actual = "false";
    
    if (expected != actual)
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "Okay"});

    return 0; 
}