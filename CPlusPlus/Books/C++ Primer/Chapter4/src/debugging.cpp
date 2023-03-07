#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector;

int main(void) {
    int ival = 0;

    if (ival++ && ival)
        cout << "Hello";
    else
        cout << "There";
}