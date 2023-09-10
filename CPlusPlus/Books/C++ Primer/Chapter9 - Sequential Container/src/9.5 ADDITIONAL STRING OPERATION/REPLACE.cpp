#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "C++ Primer 4th edition.";
    // equivalent way to replace "4th" by "5th"
    str.erase(11, 3);
    str.insert(11, "5th");
    // using replace
    str.replace(11, 3, "5th");

    return 0;
}