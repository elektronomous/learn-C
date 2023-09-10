#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str("ab2c3d7R4E6"),
           numbers("0123456789"),
           alpha_lower("abcdefghijklmnopqrstuvwxyz"),
           alpha_upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    
    string::size_type pos = 0;

    cout << "Search number first: " << endl;
    while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
        cout << "The number is found in index: " << pos << endl;
        ++pos;
    }

    cout << "Search alphabet then: " << endl;
    // reset the position
    pos = 0;

    string str2(str);
    for (char &chr: str2)
        if (isalpha(chr))
            chr = tolower(chr);

    while ((pos = str2.find_first_of(alpha_lower, pos)) != string::npos) {
        cout << "The alpha is found in index: " << pos << endl;
        ++pos;
    }    
}