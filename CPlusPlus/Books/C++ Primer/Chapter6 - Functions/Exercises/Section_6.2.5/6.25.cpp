#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

int main(int argc, char *argv[]) {
    string strTotal;

    for (size_t i = 0; i < 2; i++)
        strTotal += argv[i];
    
    cout << "The result of concatenate the string: " << strTotal << "\n";

    return 0;
}