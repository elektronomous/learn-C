#include <iostream>
#include <functional>   // bind, ref, cref
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check_size(const string &str, string::size_type sz) {
    return str.size() >= sz;
}

int main(void) {
    vector<string> words {
        "Use",
        "bind",
        "and",
        "check_size",
        "to",
        "find",
        "the",
        "first",
        "element",
        "in",
        "a",
        "vector",
        "of"
    };

    // first short the words
    cout << "First short the words: " << endl;
    sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " ";});
    cout << endl;

    // then find the first word that has length at least greater than 6, for example
    vector<string>::iterator find6 = find_if(words.begin(), words.end(), bind(check_size, placeholders::_1, 6));

    if (find6 != words.end())
        cout << "The first word that has at least 6: " << *find6 << endl;
    else 
        cout << "There's now word that's length 6" << endl;
    
    return 0;
}