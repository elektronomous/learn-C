#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void) {
    string input;

    // prompt user
    cout << "Enter a series of characters: " << endl;
    getline(cin, input);

    for (decltype(input.size()) n = 0; n < input.size(); n++) {
        if (isalpha(input[n])) 
            input[n] = toupper('X');
    }

    cout << "The string: " << input << endl;

    return 0;
}