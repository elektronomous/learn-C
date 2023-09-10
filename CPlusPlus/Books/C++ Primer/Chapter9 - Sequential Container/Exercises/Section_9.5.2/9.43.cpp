#include <iostream>
#include <string>

using namespace std;

string replaceWord(string &str, const string &oldVal, const string &newVal) {
    string::size_type match_counter = 0;
    string::iterator match_str;
    string::iterator itStr = str.begin();
    string::const_iterator itOldStr = oldVal.begin();
    

    while (itStr != str.end()) {
        if (*itStr == *itOldStr) {
            match_counter++;
            itOldStr++;
        } else {
            match_counter = 0;
            itOldStr = oldVal.begin();
        }

        itStr++;
        /*
            If you wonder why we advanced the iterator first then
            then using the match_counter?
            If you put the iterator itStr in the last statement on this 
            block, and you've found the word. the operation of match_str
            won't be accurate since we need the itStr to be advanced to
            so when the subtraction is perform. we get the exactly the length
            of the word. For example: "World" is found, then the itStr would be:

                                      itStr
                                       |
                            "Hello World"
            
            if you subtract the itStr by the match_counter, you'll end up to the space

        */
        
        // if the string we found on is the same size as the old string
        if (match_counter == oldVal.size()) {
            // because we afraid the iterator would be invalidated
            // so store the length before inserted word to the beginnning of the string
            string::size_type lengthBeforeWordToBeReplace = (itStr - match_counter) - str.begin();

            // point to the first character's the word to be replaced
            match_str = itStr - match_counter;
            // then replace
            str.erase(match_str, match_str + match_counter);
            // invalidated here, update the match_str
            match_str = str.begin() + lengthBeforeWordToBeReplace;
            // inserted here
            str.insert(match_str, newVal.begin(), newVal.end());

            // reset the old string iterator
            itOldStr = oldVal.begin();

            // update the iterator again
            itStr = str.begin() + lengthBeforeWordToBeReplace + newVal.size();
        }            

    }

    return str;
}
int main(void) {
    string myWords = "Hello World with Jupiter";
    replaceWord(myWords, "with", "and");
    replaceWord(myWords, "World", "Pluto");

    cout << myWords << endl;

    return 0;
}

/*
Hello World with Jupiter
            with
             ||||
*/