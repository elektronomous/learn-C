#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    // more verbose way to count number of times each word occurs in the input
    map<string, size_t> word_count;     // empty map from string to size_t
    string word;

    while (cin >> word) {
        // insert an element with key equal to word and 1
        // if word is already in word_count, insert does nothing and the bool value is false
        pair<map<string, size_t>::iterator, bool> returnFromInsert = word_count.insert({word, 1});
        if (!returnFromInsert.second)           // word was already in word_count
            ++returnFromInsert.first->second;    // increment the counter;
    }
}