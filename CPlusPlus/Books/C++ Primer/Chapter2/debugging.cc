#include <iostream>
#include <cstring>
/* 
NOTE

 */

int main(void) {
    int i = 0;
    const int ci = i;

    auto *p = &ci;

    std::cout << *p << std::endl;

    return 0;
}