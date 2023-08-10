#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "HOW TO USE PROGRAM:\n";
        cerr << "8.10 <inputFile>\n";
        return 1;
    }

    ifstream in(argv[1]);

    // if the file is invalid
    if (in.fail()) {
        cerr << "input file is invalid.\n";
        return 1;
    }

    vector<string> vLines;
    string line, word;      // line for hold a line, word for word

    // get each of the line of the file
    while (getline(in, line))
        // store each line into vectors
        vLines.push_back(line);
    
    // read line using istring stream
    for (const string &eachLine: vLines) {
        istringstream iString(eachLine);
        // read the whole line
        while (iString >> word) 
            cout << word << " ";
        cout << endl;
    }

    // close the input file
    in.close();

    return 0;
}