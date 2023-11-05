#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    // count the number of times each word appear in the input
    map<string, size_t> word_count;         // empty map from string to size_t

    string word;
    while (cin >> word)
        ++word_count[word];         // fetch and increment the counter for word
    
    for (const pair<const string, size_t>& w: word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;

    return 0; 
}