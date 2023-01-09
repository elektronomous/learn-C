#include <iostream>
#include <cstring>
/* 
NOTE

 */

int main(void) {
    int i, &ri = i;

    i = 5;
    ri= 20;

    std::cout << i << " " << ri << std::endl;
    
    return 0;
}