#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &vstr) {
    // sort it first
    sort(vstr.begin(), vstr.end());

    // end of the unique words
    vector<string>::iterator itEndOfUnique = unique(vstr.begin(), vstr.end());
    cout << "After Unique: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;

    // erasing the unique words
    vstr.erase(itEndOfUnique, vstr.end());
    cout << "After Erase the Unique: " << endl;
    for (const string &word: vstr)
        cout << word << " ";
    cout << endl;
}

int main(void) {
    vector<string> words;
    string str;

    cout << "Enter string of words: " << endl;
    while (cin >> str)
        words.push_back(str);
    
    cout << "You've enter words: " << endl;
    for (const string &word: words)
        cout << word << " ";
    cout << endl;



    return 0;
}