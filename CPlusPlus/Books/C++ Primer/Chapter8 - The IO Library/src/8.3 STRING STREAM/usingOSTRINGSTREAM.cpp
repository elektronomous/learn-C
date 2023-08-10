#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool valid(const string &str);
string getFormat(const string &str);

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
        record >> info.name;        // read the name
        while (record >> word)      // read the phone numbers
            info.phones.push_back(word);    // and store them
        
        people.push_back(info);     // append this record to people
    }

    for (const PersonInfo &entry: people) {
        ostringstream formatted, badNums;       // Object created in each loop
        // check the number
        for (const string &nums: entry.phones) {  // for each number
            if (!valid(nums)) {
                badNums << " " << nums;           // string in badNums;
            } else {
                // "writes" to formatted string
                formatted << " " << getFormat(nums);
            }

            if (badNums.str().empty())          // there were no bad numbers
                cout << entry.name << " "         // print the name
                     << formatted.str() << endl;  // and reformatted numbers
            else 
                cerr << "Input error: " << entry.name
                     << " invalid number(s) " << badNums.str() << endl; 
        }
    }

    return 0;
}