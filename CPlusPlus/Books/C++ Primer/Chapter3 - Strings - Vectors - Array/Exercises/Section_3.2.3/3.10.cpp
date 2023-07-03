#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string input;

    // prompt user
    cout << "Enter a series of characters: " << endl;
    getline(cin, input);

    for(char &c: input) {
        if (ispunct(c))
            c = ' ';
    }

    cout << "String result: " << input << endl;

    return 0;
}