#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::string;

int main(void) {
    unsigned short int short_val = 32768;

    std::cout << short_val << std::endl;

    std::cout << -30 / 3 * 21 % 4 << std::endl;

    const char *cp = " "; // empty string

    if (*cp)
        cout << "True, it's empty string" << endl;

    return 0;
}