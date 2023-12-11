#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

class DummyQueryResult;
class DummyTextQuery;
ostream& print(ostream &, const DummyQueryResult &);

class DummyQueryResult {
    friend ostream& print(ostream &os, const DummyQueryResult &);
    public:
        DummyQueryResult(DummyTextQuery *tq):
            result(tq) {}
        DummyQueryResult(const string &s):
            status(s) {}
        
        void checkResult(void) const {
            cout << status << endl;
        }

    private:
        shared_ptr<DummyTextQuery> result;
        string status;
};

class DummyTextQuery {
    friend class DummyQueryResult;
    public:
        DummyTextQuery(ifstream &in) {
            // check if the program can read the file
            if (in.fail())
                throw runtime_error("The file is invalid");
            
            // we read the input file
            string eachWordsPerLine;

            while (getline(in, eachWordsPerLine)) {
                wordsPerLine.push_back(eachWordsPerLine);

                // inspect each word and its line numbers
                istringstream inputStr(eachWordsPerLine);
                string word;

                while (inputStr >> word)
                    wordMapLineNumber[word].insert(wordsPerLine.size());
            }
            
        }

        DummyQueryResult query(const string &);
        /*
             
            return DummyQueryResult(make_shared<DummyTextQuery>(this))) 
        */

        vector<string> getWordsPerLine() const {
            return wordsPerLine;
        }

        map<string, set<size_t>> getWordMapLineNumber() const {
            return wordMapLineNumber;
        }

        size_t howManyWordInFile() const {
            return nWordOnFile;
        }

        string getTheQueryStr() const {
            return queryStr;
        }


    private:
        vector<string> wordsPerLine;
        map<string, set<size_t>> wordMapLineNumber;
        size_t nWordOnFile;
        string queryStr;

};

DummyQueryResult DummyTextQuery::query(const string &q) {
    // store the new query into our data member
    queryStr = q;
    // reset the counter of words
    nWordOnFile = 0;

    for (const string &lineStr: wordsPerLine) {
        // how many s in each line
        size_t pos = 0;
        while ((pos = lineStr.find(q,pos)) != string::npos) {
            pos++;
            nWordOnFile++;
        }
    }

    if (nWordOnFile)
        return DummyQueryResult(new DummyTextQuery(*this));

    return DummyQueryResult("The string isn't found");
}

ostream& print(ostream &os, const DummyQueryResult &dq) {
    // show how many times the words is occurs
    cout << dq.result->getTheQueryStr() << "Occur " << dq.result->howManyWordInFile() << endl;

    // now show the line and the corresponding word
    for (const size_t &lineNumber: dq.result->getWordMapLineNumber()[dq.result->getTheQueryStr()]) {
        cout << "(line " << lineNumber << ") " << dq.result->getWordsPerLine()[lineNumber] << endl;
    }

    return os;
}