#include <iostream>
#include <cctype>
#include <string>

using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    string str("Muhammad");

    // begin() => indirect access to the first element of the string
    string::iterator it_str = str.begin();
    // end() => denotes the one-past the end of the element
    string::iterator end_it_str = str.end();

    for (;it_str != end_it_str; it_str++) 
        // using dereference operator(*) to get the value inside iterator
        cout << *it_str << " ";
    cout << endl;
    
    return 0;


}