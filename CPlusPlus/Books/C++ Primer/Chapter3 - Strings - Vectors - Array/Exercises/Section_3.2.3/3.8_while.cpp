#include <iostream>
#include <cctype>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) { 
    string input;

    // prompt user
    cout << "Enter a series of characters: " << endl;
    getline(cin, input);

    string::size_type str_size = input.size(), n = 0;

    while (n < str_size) {
        if (isalpha(input[n])) {
            input[n] = toupper('x');
        }
        n++;
    }

    cout << "String result: " << input << endl;

    return 0;
}