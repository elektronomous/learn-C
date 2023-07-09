#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

// compare to this function

const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

// now look at the type of the function.

