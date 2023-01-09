#include <iostream>
#include <cstring>
/* 
NOTE

 */

int main(void) {
    int *p1;

    if(p1) {
        std::cout << "initialized" << std::endl;
    } else {
        std::cout << "uninitialized" << std::endl;
    }
    return 0;
}