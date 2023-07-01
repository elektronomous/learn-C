#include <iostream>
#include <string>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    string str;

    while (cin >> str)
        ;   // we aren't doing anything
    
    for (; cin >> str; )
        ;
    
    return 0;
}