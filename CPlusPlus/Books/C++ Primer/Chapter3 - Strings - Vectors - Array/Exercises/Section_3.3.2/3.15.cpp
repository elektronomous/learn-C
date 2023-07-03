#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::string;

int main(void) {
    vector<string> vstr;
    string input;

    // prompt user to enter values
    while(cin >> input) {
        // add element and initialize the element using the input value
        vstr.push_back(input);
    }

    cout << "You input value: \"";
    for (string &val : vstr) 
        cout << val << " ";
    cout << "\"" << endl;

    return 0;
}