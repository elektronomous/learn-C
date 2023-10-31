#include <iostream>
#include <functional>   // bind
#include <vector>
#include <string>

using namespace std;

void print(ostream &os, const string &s, char c) {
    os << s << c;
}

int main(void) {
    vector<string> name {
        "Muhammad",
        "Faza",
        "Akbar",
        "Anggun",
        "Fuji",
        "Lestari"
    };

    /*
        By default, the arguments to bind that are not placeholders are copied into the
        callable object that bind returns.
    */
//    for_each(name.begin(), name.end(), bind(print, cout, placeholders::_1, ' ')); => error
    for_each(name.begin(), name.end(), bind(print, ref(cout), placeholders::_1, ' '));

}