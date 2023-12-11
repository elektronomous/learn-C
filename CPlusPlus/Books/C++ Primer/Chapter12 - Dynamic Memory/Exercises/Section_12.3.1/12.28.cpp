#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void queryFor(const string &q, ifstream &in) {
    vector<string> textPerLine;
    map<string, set<size_t>> wordMapLineNum;
    string text;
    size_t nWords = 0;

    // build the container for the filetext
    while (getline(in, text)) {
        // get the text per line store to vector
        textPerLine.push_back(text);

        // now store each of word of the text into map
        string word;
        istringstream inputWord(text);

        // get the word on text per line
        while (inputWord >> word){
            // count the same word
            if (word == q) nWords++;
            // store the word and it's corresponding line number
            wordMapLineNum[word].insert(textPerLine.size());
        }
    }
    if (nWords) {
        cout << q << " occur " << nWords << (nWords > 1 ? " times": " time") << endl;

        // show the line numbers
        set<size_t> lineNumbers = wordMapLineNum[q];
        for (const size_t &lineNum: lineNumbers)
            cout << "\t(line " << lineNum << ") " << textPerLine[lineNum-1] << endl;

    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    while (true) {
        ifstream in(argv[1]);

        // check the file
        if (in.fail()) {
            cerr << argv[1] << " is an invalid file." << endl;
            return -1;
        }

        cout << "Enter the word you want to search: ";
        string queryString;
        
        if (!(cin >> queryString) || queryString == "q") break;
        queryFor(queryString, in);

        in.close();
    }


    return 0;
}