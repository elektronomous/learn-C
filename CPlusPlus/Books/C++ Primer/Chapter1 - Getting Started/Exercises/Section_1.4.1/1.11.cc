#include <iostream>

int main(void) {
    int start = 0, end = 0;

    std::cout << "Enter start and end number: " << std::endl;
    std::cin >> start >> end;

    while (end >= start) {
        std::cout << start << std::endl;
        ++start;
    }

    return 0;
}