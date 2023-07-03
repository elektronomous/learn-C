#include <iostream>

int main(void) {
    std::cout << "/*";  // legal
    std::cout << "*/";  // legal
    std::cout << /* "*/" */;    // error
    std::cout << /*     "*/" /* "/*" */;    // error

    return 0;
}