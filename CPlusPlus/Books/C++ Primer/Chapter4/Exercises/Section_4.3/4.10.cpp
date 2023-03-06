#include <iostream>

int main(void) {

    int x;

    while (std::cin >> x && x != 42)
        std::cout << "You've entered: " << x << std::endl;
    
    return 0;
}