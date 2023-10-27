#include <iostream>
#include <vector>
#include <functional> // bind, ref, cref
#include <algorithm>
#include <string>

using namespace std;

bool check6(const string &s, string::size_type sz) {
    return s.size() >= sz;
}


int main(void) {
    vector<string> words { 
        "in",
        "addition",
        "to",
        "the",
        "iterators",
        "that",
        "are",
        "defined",
        "for",
        "each",
        "of",
        "the",
        "containers"
    };

    int howManyWordsThats6 = count_if(words.begin(), words.end(), bind(check6, placeholders::_1, 6));
    cout << "The words that has length 6: " << howManyWordsThats6 << endl;

    return 0;
}