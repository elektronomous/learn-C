#include <iostream>
#include <fstream>

using namespace std;

string ascender("bdfhjklt");
string descender("gjpqy");

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "HOW USE PROGRAM: " << endl;
        cerr << "9.49 <filename>" << endl;
        return 1;
    }

    ifstream in(argv[1]);

    if (in.fail() || in.bad()) {
        cerr << "<filename> is failed to be opened" << endl;
        return -1;
    }

    string inputStr, longestWord;

    while (in >> inputStr) {
        if ((inputStr.find_first_of(ascender)) == string::npos && (inputStr.find_first_of(descender)) == string::npos)
            if (inputStr.size() > longestWord.size())
                longestWord = inputStr;
    }

    cout << "The longest word that has no ascender and descender: " << endl;
    cout << longestWord << endl;

    in.close();
    return 0;
}