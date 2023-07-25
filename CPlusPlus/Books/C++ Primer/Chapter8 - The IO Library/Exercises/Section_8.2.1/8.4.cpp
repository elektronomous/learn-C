#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void storeIntoVect(istream &is) {
    vector<string> vStr;
    string str;

    while (getline(is, str))
        vStr.push_back(str);
    

    for (const string &s: vStr)
        cout << s << "\n";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "HOW TO USE PROGRAM:\n";
        cerr << "8.4 <inputFname>\n";
        return 1;
    }

    // open the filename after the program name
    ifstream in(argv[1]);

    if (in.fail()) {
        cerr << "You've opened an invalid file. Check the file/folder name.\n";
        return 1;
    }

    // store the reading file into vector
    storeIntoVect(in);

    in.close();
    
    return 0;
}