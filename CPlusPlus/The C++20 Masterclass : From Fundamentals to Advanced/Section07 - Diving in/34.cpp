#include <iostream>

int addNumbers( int first_param, int second_param) {
    int sum = first_param + second_param;

    return sum;
}

int main(void) {
    int first_number {3};
    int second_number {5};

    std::cout << "First number: " << first_number << std::endl;
    std::cout << "Second number: " << second_number << std::endl;

    int sum = addNumbers(first_number, second_number);

    std::cout << "Sum : " << sum << std::endl;

    sum = addNumbers(10, 35);
    
    std::cout << "Sum: " << sum << std::endl;

    std::cout << "Sum : " << addNumbers(3,50) << std::endl;

    return 0;
}