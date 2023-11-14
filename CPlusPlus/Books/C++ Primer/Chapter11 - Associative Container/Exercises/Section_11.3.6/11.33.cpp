#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string> createRules(const ifstream &);
string translate(const map<string, string> &, const string &s);

void word_transform(ifstream &rulesFile, ifstream &inputFile) {
    // create the rules in the form of a mapped file
    map<string, string> dictionary = createRules(rulesFile);
    string line;

    // read each word of the input file
    while (getline(inputFile, line)) {
        istringstream stream(line);
        string word;

        while (stream >> word) {
            bool makeSpace = true;

            if (makeSpace)
                makeSpace = false;
            else
                cout << " ";            // create space after transformation

            // for esthetic program, you need the to transform the word
            cout << translate(dictionary, word);
        }
        cout << endl;               // process to the next line 
    }
}

string translate(const map<string, string> &dictFile, const string &s) {
    map<string, string>::const_iterator findWord = dictFile.find(s);

    if (findWord != dictFile.cend())
        return findWord->second;
    
    return s;
}