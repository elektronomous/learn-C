#include <iostream>
#include <string>
#include <cctype>


using std::cout,
      std::cin,
      std::endl,
      std::string;

void throw_runtime_2(void) {
    throw std::runtime_error("this throw from function throw_runtime_2");
}
void throw_runtime(void) {
    throw_runtime_2();
}

int main(void) {
    try {
        throw_runtime();
    } catch (std::runtime_error &err) {
        cout << "main function handle: " << err.what() << endl;
    }

    return 0;
}