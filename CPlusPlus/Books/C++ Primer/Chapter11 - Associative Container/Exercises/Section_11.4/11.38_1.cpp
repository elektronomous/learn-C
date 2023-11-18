#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
    unordered_map<string, size_t> word_count;
    string word;

    while (cin >> word) 
        word_count[word]++;
    
    for (const pair<const string, size_t> &p: word_count)
        cout << p.first << " occur " << p.second << (p.second > 1? " times." : "time.") << endl;
    
    return 0;
}