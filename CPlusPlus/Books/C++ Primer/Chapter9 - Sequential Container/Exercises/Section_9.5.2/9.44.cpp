#include <iostream>
#include <string>

using namespace std;

string replaceWord(string &s, const string &oldVal, const string &newVal) {
    string::size_type match_counter = 0;
    string::iterator itStr = s.begin();

    string::const_iterator itOldStr = oldVal.begin();

    while (itStr != s.end()) {
        if (*itStr == *itOldStr) {
            match_counter++;
            itOldStr++;
        } else {
            itOldStr = oldVal.begin();
            match_counter = 0;
        }

        itStr++;

        if (match_counter == oldVal.size()) {
            // because after replace the iterator would be invalidate
            // so store the length of string from the begining
            string::size_type lengthBeforeInsert = (itStr - match_counter) - s.begin();
            
            // replace
            s.replace(itStr - match_counter, itStr, newVal.begin(), newVal.end());

            // reset the old iterator string
            itOldStr = oldVal.begin();

            // because the string invalidate, update the string iterator
            itStr = s.begin() + lengthBeforeInsert + newVal.size();

        }
    }

    return s;
}

int main(void) {
    string myWords = "Hello There, Jupiter, There";

    replaceWord(myWords, "Jupiter", "Pluto");
    replaceWord(myWords, "There", "Aqua");

    cout << "My words after replace: " << myWords << endl;

    return 0;
}