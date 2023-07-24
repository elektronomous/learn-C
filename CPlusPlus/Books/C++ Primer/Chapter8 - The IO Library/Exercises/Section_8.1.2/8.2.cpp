#include <iostream>
#include <string>

using namespace std;

istream& rdUntilEof(istream& is) {
    string s;
    // state before cin get problem
    ios_base::iostate old_state = is.rdstate();

    is >> s;
    cout << "You've typed: " << s << endl;

    if (is.eof()) {
        cout << "eof() is called\n";
        // if (is.bad())
        //     cout << "bad() is called\n";
        // if (is.fail())
        //     cout << "fail() is called\n";
        is.clear();
        is.setstate(old_state);
        getline(is, s);
    }
    return is;
}

int main(void) {
    rdUntilEof(cin);
    rdUntilEof(cin);

    return 0;
}