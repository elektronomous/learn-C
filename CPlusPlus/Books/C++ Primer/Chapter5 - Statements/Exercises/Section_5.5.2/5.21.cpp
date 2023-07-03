#include <iostream>
#include <string>
#include <iterator>
#include <cctype>

using std::cin,
      std::cout,
      std::endl,
      std::string;

int main(void) {
    string str[] = {"enter", "two", "Strings", "Strings", "you", "can", "it"};
    string *toStr = std::begin(str) + 1;

    while (toStr != std::end(str) && toStr++) {
        if (std::islower((*toStr)[0]))
            continue;

        if (*toStr == *(toStr-1)) {
            cout << "The word \"" << *toStr << "\" is occured twice in succession." << endl;
            break;
        }
    }

    if (toStr == std::end(str))
        cout << "There's no word was repeated." << endl;
    
    return 0;
}