#include <string>
#include <iostream>

using namespace std;

int main(void) {
    const char *cp = "Stately, plump buck";
    string str;

    str.assign(cp, 7);      // Assign "Stately" to str;
}