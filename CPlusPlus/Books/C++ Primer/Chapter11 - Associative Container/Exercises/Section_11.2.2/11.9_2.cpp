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
        cout << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    // check the file
    if (inputFile.fail()) {
        cout << "Invalid file." << endl;
        return 1;
    }

    map<lineNumbers, word> trackWords;
    string eachLineOfWords, eachWord;
    // start from line 1
    int lineNumber = 1;

    while (getline(inputFile, eachLineOfWords)) {
        istringstream inputString(eachLineOfWords);
        while (inputString >> eachWord) {
            
        }
    }

}