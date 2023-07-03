#include <iostream>
#include <vector>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string,
      std::vector;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
    vstr vs{"How", "Many", "Elements", "", "Are", "There"};

    // -> (arrow operator) => access the element member
    for (vstr::const_iterator it = vs.cbegin(); it != vs.cend(); it++) 
        if (it->empty())
            cout << "The empty element is on index " << vs.cend() - it << endl;
    
    return 0;
}