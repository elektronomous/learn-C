#include <iostream>
#include <cctype>       // to use the isxxx() function
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(void) {
    string str = "Hello World!!!!!!!!!";
    string::size_type punct_cnt = 0;

    for(char c: str) {  // every character in str, copy to c
        if (ispunct(c)) {
            ++punct_cnt;
        }
    }

    cout << "The punctuation on \"" << str << "\" is "
         << punct_cnt
         << endl;


    return 0;    
}