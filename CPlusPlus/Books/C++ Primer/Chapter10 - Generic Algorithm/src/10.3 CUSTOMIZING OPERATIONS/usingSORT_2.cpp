#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// short the vector of words by its size;
int main(void) {
    vector<string> vstr {"Muhammad", "Faza", "Akbar", "Anggun", "Fuji", "Lestari"};

    cout << "Before short by length: " << endl;
    for (const string &str: vstr)
        cout << str << " ";
    cout << endl;

    // short by length
    sort(vstr.begin(), vstr.end(), isShorter);

    cout << "After shorted by length: " << endl;
    for (const string &str: vstr)
        cout << str << " ";
    cout << endl;

    return 0;
}