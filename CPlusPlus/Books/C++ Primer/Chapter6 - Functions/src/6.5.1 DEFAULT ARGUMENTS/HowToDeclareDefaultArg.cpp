#include <iostream>
#include <string>

using namespace std;

string screen(size_t, size_t, char=' ');
// you can redeclare this but you can declare with default argument
string screen(size_t=40, size_t=80, char);
// you cannot redeclare this and remove the default value.