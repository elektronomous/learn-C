#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    std::string name;

    cout << "Enter your name: " << endl;
    // enter your name
    std::getline(cin, name);

    cout << "Hello " << name << ". Welcome to C++ Programming" << endl;

    return 0;
}