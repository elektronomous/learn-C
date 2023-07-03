#include <iostream>
#include <vector>
#include <string>

using std::cin,
      std::vector, 
      std::string,
      std::cout,
      std::endl;

using vint = vector<int>;
using vstr = vector<string>;

int main(void) {
    string input;
    vstr vs;

    // prompt user
    cout << "Input words: " << endl;

    while(cin >> input) 
        vs.push_back(input);

    // change every word to uppercase
    for (string &s : vs) 
        for (char &c : s) 
            c = toupper(c);
        
    // show the result
    cout << "The result: " << endl;
    for (string &s : vs) 
        cout << s << " ";
    cout << endl;

    return 0;
}
