#include <iostream>
#include <string>

using namespace std;

istream& rdUntilEof(istream& is) {
    string s;

    while (is >> s)
        cout << s;

    if (is.eof())
        // reset the stream
        is.clear();
    return is;
}