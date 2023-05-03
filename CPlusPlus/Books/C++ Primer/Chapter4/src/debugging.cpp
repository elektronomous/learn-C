#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::string;

int main(void) {
    vector<string> vint {"hey", "there"};
    vector<string>::iterator toVint = vint.begin();

    cout << toVint++->size() << endl;
    cout << toVint->size() << endl;
    return 0;
}