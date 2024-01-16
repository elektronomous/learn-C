#include <iostream>
#include <string>

using namespace std;

class ReadString {
    public:
        ReadString(istream &in = cin):
            is(in) { }
        
        string operator()(string &s) {
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
    string str;

    scanner(str);

    cout << str << endl;

    return 0;
}