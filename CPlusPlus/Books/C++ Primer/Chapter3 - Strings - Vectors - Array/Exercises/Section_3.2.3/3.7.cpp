#include <iostream>
#include <string>
#include <cctype>   // to use isxxx() function

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void) {
    string input;

    // prompt user
    cout << "Enter a string of characters: " << endl;
    getline(cin, input);

    for (auto &c: input) /* every char in str, is aliases to c */
        if (isalpha(c))
            c = toupper('x');
    cout << input << endl;

    return 0;
}