#include <iostream>
#include <cstring>
/* 
NOTE

 */

int main(void) {
    int i = 10;
    int *toI = &i;
    const int *toII = toI;

    std::cout << *toII << std::endl;
    return 0;
}