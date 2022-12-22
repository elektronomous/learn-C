#include <iostream>

int main(void) {
    int sum = 0;

    for(int i = -100; i <= 100; ++i) {
        sum += i;
    }
    // the for-loop will loop from -100 to 100, which means 200 times
    
    std::cout << "The value of sum after 200 times looping: "
              << sum << std::endl;

    return 0;
}