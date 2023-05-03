#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::string;

int main(void) {
    string s = "word";
    string p1 = s + ((s[s.size() - 1] == 's') ? "" : "s");

    cout << p1 << endl;

    return 0;
}