#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "Hello World";

    str.erase(str.size() - 5, 5);       // erase "World"
}