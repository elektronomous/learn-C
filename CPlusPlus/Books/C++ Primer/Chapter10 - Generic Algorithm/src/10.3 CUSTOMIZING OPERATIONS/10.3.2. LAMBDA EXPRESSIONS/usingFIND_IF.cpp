#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void) {
        vector<string> words {
        "The",
        "empty",
        "capture",
        "list",
        "indicates",
        "that",
        "this",
        "lambda",
        "will",
        "not",
        "use",
        "any",
        "local",
        "variables", 
        "from",
        "the",
        "surrounding",
        "function.",
        "The",
        "lambda’s",
        "parameters,",
        "like",
        "the",
        "parameters", 
        "to",
        "isShorter,",
        "are",
        "references",
        "to",
        "const",
        "string"
    };
    // short the words
    sort(words.begin(), words.end());

    // eliminate the duplicate
    std::vector<string>::iterator endOfUnique = unique(words.begin(), words.end());
    words.erase(endOfUnique, words.end());

    // using stable_sort to sort alphabetically on each size
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

    // get an iterator to the first element whose size() is >= sz
    std::string::size_type sz = 5;

    std::vector<string>::iterator firstFive = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });

    if (firstFive != words.end()) {
        cout << "find_if returns the words: " << *firstFive << endl;
        cout << "There are " << words.end() - firstFive << " words that each of its character has more than " << sz << " characters" << endl;
    } else
        cout << "find_if returns words.end()" << endl;
    


    return 0;
}