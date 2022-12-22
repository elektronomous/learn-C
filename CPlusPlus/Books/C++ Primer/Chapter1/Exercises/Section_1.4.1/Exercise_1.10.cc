#include <iostream>

int main(void) {
    int val = 10;

    while(val >= 0) {
        std::cout << "The val: " << val << std::endl;
        --val;
    }

    return 0;
}