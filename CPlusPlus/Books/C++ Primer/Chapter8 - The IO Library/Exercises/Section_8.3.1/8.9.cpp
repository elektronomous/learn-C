#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

istream& rdUntilEof(istream& is) {
    string s;

    while (is >> s)
        cout << s;
    cout << endl;
    
    return is;
}

int main(int argc, char *argv[]) {
    struct PersonInfo {
        string name;
        vector<string> phones;
    };

    string line, word;      // will hold a line and word from input, respectively
    vector<PersonInfo> people;

    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) {
        PersonInfo info;            // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        // read all the contents of istring object using rdUntilEof()
        rdUntilEof(record);
    }

    return 0;
}