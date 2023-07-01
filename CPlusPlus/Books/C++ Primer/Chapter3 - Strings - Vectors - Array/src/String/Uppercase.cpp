#include <iostream>
#include <cctype>       // to use the isxxx() function
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(void) {
    string str = "Hello World!!!!!!!!!";

    for(char &c: str)  // every character in str, aliases to c
        c = toupper(c);
    
    cout << "String after uppercase: " << str << endl;
    
    return 0;    
}