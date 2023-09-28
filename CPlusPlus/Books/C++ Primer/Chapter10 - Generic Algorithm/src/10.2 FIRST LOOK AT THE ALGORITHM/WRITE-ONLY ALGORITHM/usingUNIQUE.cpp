#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
The unique algorithm rearranges the input range to “eliminate” adjacent
duplicated entries, and returns an iterator that denotes the end of the
range of the unique values
*/

int main(void) {
    vector<string> notUniqueWords {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

    cout << "Not unique words: " << endl;
    for (const string &word: notUniqueWords)
        cout << word << " ";
    cout << endl;

    cout << "After unique words: " << endl;
    vector<string>::iterator itEndOfUnique = unique(notUniqueWords.begin(), notUniqueWords.end());

    for (const string &word: notUniqueWords)
        cout << word << " ";
    cout << endl;

    // now you can erase the unique words
    cout << "Erasing the unique words: " << endl;
    notUniqueWords.erase(itEndOfUnique, notUniqueWords.end());
    
    for (const string &word: notUniqueWords)
        cout << word << " ";
    cout << endl;

    return 0;
}