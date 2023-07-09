#include <iostream>
#include <string>

using namespace std;


char &get_val(string &str, string::size_type ix) {
    return str[ix];     // get_val assumes the given index is valid
}

int main(void) {
    string s("a value");

    cout << s << endl;          // prints "a value"
    get_val(s, 0) = 'A';        // changes s[0] to 'A'
    cout << s << endl;          // prints "A value";

    return 0;
}

// if the return type is a reference to const, we may not 
// assign to the result of the call.