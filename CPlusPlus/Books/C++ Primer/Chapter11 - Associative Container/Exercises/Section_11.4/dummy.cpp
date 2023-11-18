#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    string words = "Muhammad Faza Akbar";
    string getWord, anotherWord;

    istringstream is(words);

    while (is >> getWord)
        getline(is, anotherWord);
    
    cout << getWord << endl;
    cout << anotherWord << endl;

    return 0;
    
}