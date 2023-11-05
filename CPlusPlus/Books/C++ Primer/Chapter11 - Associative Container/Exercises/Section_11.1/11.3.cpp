#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main(void) {
    map<string, string::size_type> word_count;
    istream_iterator<string> readStr(cin), eof_readStr;

    while (readStr != eof_readStr)
        ++word_count[*readStr++];
    
    for (const pair<const string, string::size_type> &w: word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
}