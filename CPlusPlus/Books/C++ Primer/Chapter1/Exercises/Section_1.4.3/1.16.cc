#include <iostream>

int main(void) {
    int number1 = 0,
        number2 = 0,
        number3 = 0,
        number4 = 0,
        number5 = 0,
        sum = 0;

    std::cout << "Enter number1: " << std::endl;
    std::cin >> number1;
    std::cout << "Enter number2: " << std::endl;
    std::cin >> number2;
    std::cout << "Enter number3: " << std::endl;
    std::cin >> number3;
    std::cout << "Enter number4: " << std::endl;
    std::cin >> number4;
    std::cout << "Enter number5: " << std::endl;
    std::cin >> number5;

    sum += number1 + number2 + number3 + number4 + number5;

    std::cout << "the sum of 5 numbers are: "
              << sum << std::endl;


    return 0;
}