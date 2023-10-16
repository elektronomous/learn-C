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

    // sort it first
    sort(words.begin(), words.end());

    // get the iterator to the first words that is unique
    std::vector<string>::iterator endOfUnique = unique(words.begin(), words.end());
    
    // erase the unique
    words.erase(endOfUnique, words.end());

    // use stable_sort to get words sorted by size and alphabetically
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

    string::size_type sz = 5;
    // get the first element of word that its character has more than 5.
    vector<string>::iterator firstFive = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; } );

    // print each of word start from firstFive to words.end()
    for_each(firstFive, words.end(), [] (const string &s) { cout << s << " "; });
    cout << endl;

    return 0;
}