#include <iostream>
#include <string>

using namespace std;

const string &manip(void) {
    string ret;

    if (!ret.empty())
        return ret;     // WRONG: return a reference to a local object
    else
        return "Empty"; // WRONG: "Empty" is a local temporary string
}
