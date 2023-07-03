#include <iostream>
#include <cctype>
#include <string>

using   std::cin,
        std::cout,
        std::endl,
        std::string;

int main(void) {
    string str("Linux Basic for Hacker");

    // iterate through the string and change each lowercase to uppercase
    for(string::iterator beg = str.begin();
        beg != str.end() && !isspace(*beg);
        beg++){
            *beg = toupper(*beg);
        }
    
    // show result
    cout << "Result: " << str << endl;

    return 0;

}