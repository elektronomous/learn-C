#include <iostream>
#include <string>
#include <cctype>


using std::cout,
      std::cin,
      std::endl,
      std::string;

void throw_runtime(void) {
    try {
        throw std::runtime_error("this is throw from throw_runtime function.");
    } catch (std::runtime_error &err) {
        cout << err.what() << endl;
    }
}

int main(void) {
    int x;
    cin >> x;
}