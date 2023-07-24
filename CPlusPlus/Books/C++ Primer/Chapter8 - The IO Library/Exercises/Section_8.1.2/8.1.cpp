#include <iostream>
#include <string>

using namespace std;

istream& rdUntilEof(istream& is) {
    string s;

    is >> s;

    if (is.eof())
        // reset the stream
        is.clear();
    return is;
}