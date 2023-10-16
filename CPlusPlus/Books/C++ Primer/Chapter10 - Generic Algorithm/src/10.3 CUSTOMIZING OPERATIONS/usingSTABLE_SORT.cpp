#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(void) {
    // stable sort has advances that ordered words by size (using overloaded function)
    // and alphabetically
    vector<string> vstr {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    
    // sort it alphabetically
    cout << "before sort: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    // sort them
    sort(vstr.begin(), vstr.end());

    cout << "after sort: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    cout << "before remove duplicate words: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    // we're using unique and remove the duplicate words
    std::vector<string>::iterator endOfUnique = unique(vstr.begin(), vstr.end());
    // remove from "end of unique" to "end" of the iterator of the vstr
    vstr.erase(endOfUnique, vstr.end());

    cout << "after remove duplicate words: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    // using stable_sort
    cout << "Before stable_sort: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    // stable_sort makes the alphabetically consistent when
    // stable_sort sorts the vector by its size.
    stable_sort(vstr.begin(), vstr.end(), isShorter);

    cout << "After stable_sort: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    return 0;
}