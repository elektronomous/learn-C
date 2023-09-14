#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sumVecStr(const vector<string> &vstr) {
    int total = 0;
    string::size_type pos = 0;

    for (const string &str: vstr) {
        if ((pos = str.find_first_of("+-.0123456789")) != string::npos)
            total += stoi(str.substr(pos));
    }

    return total;
}

int main(void) {
    vector<string> vstr {"1", "asdfsfdf", "3"};

    cout << sumVecStr(vstr) << endl;

    return 0;
}