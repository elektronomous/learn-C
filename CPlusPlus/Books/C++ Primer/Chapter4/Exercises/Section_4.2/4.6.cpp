#include <iostream>

int main(void) {
    int number = 10;

    std::cout << ((number % 2 == 0) ? 
                 "It's even number" :
                 "It's odd number") << std::endl;

    return 0;
}