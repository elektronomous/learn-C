#include <iostream>
#include <string>

int main(void) {
    std::string name = "faza akbar";
    char &toName = name[0];
    toName = 'F';

    std::cout << name << std::endl;
    return 0;
}