#include <iostream>

int main(void) {
    int a = 10,
        b = 5,
        c = 2,
        d = 3;
    
    if (a > b && a > c && a > d)
        std::cout << "a is greater than b, c, d" << std::endl;
    
    return 0;
}