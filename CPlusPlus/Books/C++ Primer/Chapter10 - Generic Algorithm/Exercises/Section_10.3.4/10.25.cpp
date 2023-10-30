#include <iostream>
#include <functional>   // bind, ref, cref
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void biggies(vector<string> &vstr) {
    // first you sort the vector
    sort(vstr.begin(), vstr.end());
    // group the unique and then erase it
    vector<string>::iterator endOfUnique = unique(vstr.begin(), vstr.end());
    vstr.erase(endOfUnique, vstr.end());

    // using stable_sort to get the vstr by its size and alphabetically
    stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size();});

    // using partition to get the one past last element of words that its character has more than 5
    vector<string>::iterator endOfFive = partition(vstr.begin(), vstr.end(), bind(check_size, placeholders::_1, 5));

    for_each(vstr.begin(), endOfFive, [](const string &s) { cout << s << " " ;});
    cout << endl;
}

int main(void) {
    vector<string> words {
        "When", 
        "we",
        "define",
        "a",
        "lambda,",
        "the",
        "compiler",
        "generates",
        "a",
        "new",
        "(unnamed)",
        "class",
        "type",
        "that",
        "corresponds",
        "to",
        "that",
        "lambda"
    };

    biggies(words);

    return 0;
}