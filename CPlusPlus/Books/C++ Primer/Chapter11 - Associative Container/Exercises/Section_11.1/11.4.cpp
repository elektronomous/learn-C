#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main(void) {
    map<string, string::size_type> word_count;
    set<char> puncts {'!', '@', '#', '$', '%', '^', 
                        '&', '*', '(', ')', '_', '+', 
                        '~', '`', '-', '=', ';', '\'', 
                        ',', '.', '/', '[', ']', '\\',
                        ':', '<', '>', '?','"'
                      };
    istream_iterator<string> readStr(cin), eof_readStr;

    while (readStr != eof_readStr) {
        string lowercase;
        // and then transform the string into lower case
        transform(readStr->begin(), readStr->end(), back_inserter(lowercase), [](const char &c) { return tolower(c); });
        // erase punctuation
        for (const char &c: puncts)
            if (lowercase.find(c) != string::npos)
                lowercase.erase(lowercase.find(c));
        // enter the string into the word_count
        ++word_count[lowercase];
        // increment the stream
        readStr++;
    }
    
    for (const pair<const string, string::size_type> &w: word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
}