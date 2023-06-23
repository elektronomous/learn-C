#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(void) {
    const string hexadecimal = "0123456789ABCDEF";
    string result;
    string::size_type n = 0;

    // prompt user
    cout << "Enter a series of number seperated by space between 0 and 15"
         << "Hit Enter when finished: "
         << endl;

    while (cin >> n) {
        if (n < hexadecimal.size()) 
            // using subscript operator
            result += hexadecimal[n];
    }
    
    cout << "Hexadecimal: " << result << endl;

    return 0;
}