#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &vstr) {
    // sort words alphabetically so we can find the duplicates
    sort(vstr.begin(), vstr.end());

    // unique reorders the input range so that each word appear once in the
    // front portion of the range and returns an iterator one past the
    // unique range.
    vector<string>::iterator itEndOfUnique = unique(vstr.begin(), vstr.end());

    // erase uses a vector operation to remove the nonunique elements
    vstr.erase(itEndOfUnique, vstr.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(void) {
    vector<string> words {
        "Write", "a", "program", "that", "uses", "stable_sort", "and", "isShorter", "to", 
        "sort", "a", "vector", "passed", "to", "your", "version", "of", "elimDups", "Print",
        "the", "vector", "to", "verify", "that", "your", "program", "is", "correct"
    };

    cout << "Before sort and eliminate the words: " << endl;
    for (const string &word: words)
        cout << word << " ";
    cout << endl;

    // eliminate non-unique words/the words that repeated
    elimDups(words);

    cout << "After sort and eliminate the words: " << endl;
    for (const string &word: words)
        cout << word << " ";
    cout << endl;

    cout << "Before stable_sort: " << endl;
    for (const string &word: words)
        cout << word << " ";
    cout << endl;

    // using stable short with predicate isShorter
    stable_sort(words.begin(), words.end(), isShorter);

    cout << "After stable_sort: " << endl;
    for (const string &word: words)
        cout << word << " ";
    cout << endl;
 
    return 0;
}