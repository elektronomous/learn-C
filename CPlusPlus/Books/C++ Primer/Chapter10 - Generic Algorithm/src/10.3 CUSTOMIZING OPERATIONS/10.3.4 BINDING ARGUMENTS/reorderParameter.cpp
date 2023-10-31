#include <iostream>
#include <algorithm>
#include <functional>   // bind
#include <vector>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(void) {
    vector<string> words {
        "which", 
        "takes", 
        "a", 
        "single", 
        "parameter", 
        "of", 
        "type", 
        "int", 
        "and", 
        "returns", 
        "a", 
        "value", 
        "of", 
        "type", 
        "int"
    };

    // sort on word length, shortest to longest
    sort(words.begin(), words.end(), isShorter);
    // sort on word length, longest to shorter
    sort(words.begin(), words.end(), bind(isShorter, placeholders::_2, placeholders::_1));

    return 0;

}