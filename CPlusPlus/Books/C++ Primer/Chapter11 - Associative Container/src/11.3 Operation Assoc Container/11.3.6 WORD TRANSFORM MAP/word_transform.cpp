#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream &);
string transform(const string &, const map<string, string> &);

void word_transform(ifstream &map_file, ifstream &input) {
    map<string, string> trans_map = buildMap(map_file);         // store the transformation
    string text;            // hold each line from input

    while (getline(input, text)) {      // read  a line from input
        istringstream stream(text);     // read each word
        string word;                    // hold the word
        bool firstWord = true;          // control whether the space is inserted

        while (stream >> word) {
            if (firstWord)
                firstWord = false;
            else
                cout << " ";            // prints a space between words
            
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map);     // print the output
        }
        cout << endl;
    }
}

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> transMap;           // hold the transformation
    string key;         // a word to transform
    string value;       // phrase to use instead

    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)   // check that there's a transformation
            transMap[key] = value.substr(1);    // remove the leading space
        else
            throw runtime_error("No rule for " + key);
    }

    return transMap;
}

string transform(const string &s, const map<string, string> &m) {
    map<string, string>::const_iterator map_it = m.find(s);

    // if the word in the transformation map
    if (map_it != m.cend())
        return map_it->second;
    
    return s;
}