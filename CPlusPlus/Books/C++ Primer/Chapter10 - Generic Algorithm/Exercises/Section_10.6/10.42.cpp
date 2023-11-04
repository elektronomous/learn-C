#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

void biggies(list<string> &lstr) {
    // first sort the list of the string
    lstr.sort();

    // then remove the non-unique element's value.
    lstr.unique();
}

int main(void) {
    list<string> words {"hello", "world", "hello", "world"};

    biggies(words);
    cout << "The result after remove duplicate words: " << endl;
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}