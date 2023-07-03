#include <iostream>

int main(void) {
    int sum = 0;

    for (int val = 50; val <= 100; val++) {
        sum += val;
    }

    std::cout << "The result of sum: "
              << sum << std::endl;

    return 0;
}