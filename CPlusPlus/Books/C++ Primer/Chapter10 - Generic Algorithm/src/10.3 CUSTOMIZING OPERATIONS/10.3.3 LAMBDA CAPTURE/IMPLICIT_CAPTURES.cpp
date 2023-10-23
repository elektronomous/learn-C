#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

ostream& print(const vector<string> &vstr, const char c, ostream &os) {
    for_each(vstr.begin(), vstr.end(), [&] (const string &s) { os << s << " "; });

    // you can also mix the capture by value and reference
    
    // capture c by value, another variable outside this lambday captured by reference
    for_each(vstr.begin(), vstr.end(), [&, c/*, another variable capture by value here*/] (const string &s) { os << s << c; });
    
    // capture os by reference, another variable outside this lambda captured by value
    for_each(vstr.begin(), vstr.end(), [=, &os/*, another variable captured by ref here*/] (const string &s) { os << s << c; });


    return os;
}

int main(void) {
    vector<string> words {
        "The ", "& ", "tells ", "the ", "compiler ", "to ", "capture ", "by ", "reference, ", "and ", "the ", "= ", "says",
"the", "values ", "are ", "captured ", "by ", "value."
    };
    int sz = 5;
    // [=] implicitly capture all variable outside the lambda by value
    vector<string>::iterator findFive = find_if(words.begin(), words.end(), [=](const string &s) { return s.size() >= 5; });

    if (findFive != words.end())
        cout << *findFive << endl;
    
    // [&] implicityly capture all variable outside the lambda by reference
    print(words, ' ', cout);

    // you can also mix it
    

    return 0;
}