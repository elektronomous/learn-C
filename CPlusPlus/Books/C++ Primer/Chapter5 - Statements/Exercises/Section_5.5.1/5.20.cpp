#include <iostream>
#include <string>
#include <iterator>

using std::cin,
      std::cout,
      std::endl,
      std::string;

int main(void) {
    string str[] = {"enter", "two", "strings", "strings", "you", "can", "it"};
    string *toStr = std::begin(str) + 1;

    while (toStr != std::end(str)) {
        if (*toStr == *(toStr-1)) {
            cout << "The word \"" << *toStr << "\" occured twice in succession" << endl;
            break;
        }
        toStr++;
    }

    if (toStr == std::end(str))
        cout << "There's no word was repeated." << endl;
    
    return 0;
}