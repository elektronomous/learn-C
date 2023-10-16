#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void biggies(vector<string> &vstr) {
    // first you sort the vector
    sort(vstr.begin(), vstr.end());
    // group the unique word and then erase it
    vector<string>::iterator endOfUnique = unique(vstr.begin(), vstr.end());
    vstr.erase(endOfUnique, vstr.end());

    // using stable_sort to get the vstr sorted by its size and alphabetically
    stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

    string::size_type sz = 5;
    // using partition to get to one past last element of words that its character has more than 5.
    vector<string>::iterator endOfFive = stable_partition(vstr.begin(), vstr.end(), [sz](const string &s) { return s.size() >= sz; });

    // print only words that its character has more than 5.
    for_each(vstr.begin(), endOfFive, [](const string &s) { cout << s << " ";});
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