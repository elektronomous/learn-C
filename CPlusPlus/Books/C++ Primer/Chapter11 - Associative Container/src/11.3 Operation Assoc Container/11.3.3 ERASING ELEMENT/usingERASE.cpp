#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) {
    map<string, int> word_count {{"word", 1}, {"faza", 3}, {"hello", 5}};

    cout << "Before remove: " << endl;
    for_each(word_count.begin(), word_count.end(), [](const pair<string, int> &p) { cout << p.first << " " << p.second << endl; });

    // erase the word that's not exists
    cout << "Erase the key that's named: aque" << endl;
    if (word_count.erase("aque")) 
        cout << "the aque is erased." << endl;
    else
        cout << "..There's no key that's name \"aque\"" << endl;

    cout << "Erase the key that's named: hello" << endl;
    if (word_count.erase("hello")) 
        cout << "The word \"hello\" is erased." << endl;
    else
        cout << "..There's no key that's name \"hello\"" << endl;
    


    return 0;
}