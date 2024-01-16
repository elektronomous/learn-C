#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ReadString {
    public:
        ReadString(istream &in = cin):
            is(in) { }
        
        string operator()(string &s) const {
            is >> s;

            // if fail return empty string
            if (!is) return string();

            return s;
        }
    private:
        istream &is;

};

int main(void) {
    ReadString scanner;
    string input;
    vector<string> vstr{scanner(input), scanner(input)};

    return 0;
}