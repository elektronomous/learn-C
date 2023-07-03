#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string input, str;

    while(getline(cin, input)) {
        str += input;
    }

    cout << "String: " << str << endl;

    return 0;
    
}