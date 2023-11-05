#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(void) {
    map<string, size_t> word_count;     // empty map from string to size_t
    set<string> exclude {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};

    string word;

    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];         // fetch and increment the counter word
    
    for (const pair<const string, size_t> &w: word_count) 
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
}