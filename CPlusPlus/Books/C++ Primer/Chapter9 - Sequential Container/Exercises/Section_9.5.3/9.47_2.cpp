#include <iostream>
#include <string>

using namespace std;

int main(void) { 
    string str("ab2c3d7R4E6"),
           numbers("0123456789"),
           alpha_lower("abcdefghijklmnopqrstuvwxyz");

    string::size_type pos = 0;

    // to search number0
    cout << "The number indexes: " << endl;
    string str2(str);
    for (char &chr: str2)
        if (isalpha(chr))
            chr = tolower(chr);
    
    while ((pos = str.find_first_not_of(alpha_lower, pos)) != string::npos) {
        cout << "The number found in index: " << pos << endl;
        pos++;
    }

    // to serach alphabet then
    pos = 0;
    cout << "The alphabetic indexes: " << endl;
    while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
        cout << "The alpha found in index: " << pos << endl;
        pos++;
    }
    
    return 0;
}