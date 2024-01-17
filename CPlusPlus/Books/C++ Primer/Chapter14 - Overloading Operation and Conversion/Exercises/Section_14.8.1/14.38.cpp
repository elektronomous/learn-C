#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class cmpSize { 
    public:
        cmpSize(const size_t &theSize):
            sz(theSize) { }
        
        bool operator()(const string &s) { 
            return s.size() == sz;
        }

    private:
        size_t sz;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    // open the file
    ifstream in(argv[1]);
    string inputStr;
    vector<string> vLine;
    size_t totalWordsFrom1To10 = 0;

    if (in.fail()) {
        cerr << argv[1] << " is an invalid file." << endl;
        return -1;
    }

    while (getline(in, inputStr))   // read the file line by line
        vLine.push_back(inputStr);  // and store to the vector of strings


    for (size_t n = 1; n<=10; n++) {
        // read per line
        for_each(vLine.cbegin(), vLine.cend(), [&](const string &s)  {    
            istringstream cinStr(s);
            string inputWord;

            // read the word per line
            while (cinStr >> inputWord)
                // compare using our function-objects.
                if (cmpSize(n)(inputWord))
                    totalWordsFrom1To10++;
        });
    }

    cout << "The words that have 1 to 10 sizes are: " << totalWordsFrom1To10
         << (totalWordsFrom1To10 > 1 ? " words" : " word") << endl;

    in.close();
    return 0;
}