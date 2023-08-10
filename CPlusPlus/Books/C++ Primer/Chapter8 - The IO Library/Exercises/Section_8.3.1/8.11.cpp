#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    struct PersonInfo {
        string name;
        vector<string> phones;
    };

    string line, word;      // will hold a line and word from input, respectively
    vector<PersonInfo> people;
    istringstream record;

    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) {
        PersonInfo info;            // create an object to hold this record's data
        record.str(line);
        record >> info.name;        // read the name
        while (record >> word)      // read the phone numbers
            info.phones.push_back(word);    // and store them
        
        people.push_back(info);     // append this record to people
    }

    return 0;
}