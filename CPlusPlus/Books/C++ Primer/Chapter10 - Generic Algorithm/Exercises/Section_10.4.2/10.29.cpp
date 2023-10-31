#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << argv[0] << " <input file>" << endl;
        return 1;
    }

    ifstream inputFromFile(argv[1]);

    if (inputFromFile.fail()) {
        cout << "You've entered invalid file." << endl;
        return 1;
    }

    istream_iterator<string> readFile(inputFromFile), eof_readFile;

    /* 
    the easiest one 
        ostream_iterator<string> ostreamFile(cout, ' ');
        copy(readFile, eof_readFile, ostreamFile);
        
    another one:
        for_each(readFile, eof_readFile, [](const string &s) { cout << s << " "; });
    */
    while(readFile != eof_readFile)
        cout << *readFile++ << " " << endl;

    inputFromFile.close();
    return 0;
}