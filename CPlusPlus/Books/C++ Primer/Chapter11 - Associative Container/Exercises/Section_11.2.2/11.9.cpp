#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

typedef string word;
typedef list<int> lineNumbers;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << argv[0] << "<inputFile>" << endl;
        return 1;
    }

    // open the file
    ifstream inputFile(argv[1]);
    if (inputFile.fail()) {
        cout << "Invalid file." << endl;
        return 1;
    }

    map<word, lineNumbers> trackWords;
    string wordsPerLine, eachWord;
    string::size_type n = 1;

    while (getline(inputFile, wordsPerLine)) {
        istringstream inputString(wordsPerLine);
        while (inputString >> eachWord)
            trackWords[eachWord].push_back(n);
        // next line
        n++;
    }
    
    for (const pair<const word, lineNumbers> &p: trackWords) {
        cout << "The word " << "\"" << p.first << "\"" << " on line: " << endl;
        for (const int &lineNumber: p.second)
            cout << lineNumber << " ";
        cout << endl; 
    }

    // close the file
    inputFile.close();

    return 0;
}
