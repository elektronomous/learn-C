#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

int main(void) {
    string str1, str2;

    // enter str1
    getline(cin, str1);
    getline(cin, str2);

    if (str1 == str2) {
        cout << "The string has same characters";
    } else {
        if (str1 > str2) {
            cout << "The first string has longest characters than the second";
        } else {
            cout << "The second string has longest characters than the first";
        }
    }

    return 0;


}