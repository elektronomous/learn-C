#include <iostream>
#include <string>
#include <cctype>


using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    string name = "faza";

    bool status = std::isupper(name[0]);
    cout << status << endl;
    return 0;
}