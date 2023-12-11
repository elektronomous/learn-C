#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

class QueryResult;
class TextQuery;
ostream& print(ostream &, const QueryResult &);

class QueryResult {
    friend ostream& print(ostream &os, const QueryResult &);
    public:
        QueryResult(TextQuery *tq):
            result(tq) {}
        QueryResult(const string &s):
            status(s) {}
        


    private:
        shared_ptr<TextQuery> result;
        string status;
};

class TextQuery {
    friend class QueryResult;
    public:
        TextQuery(ifstream &in) {            
            // we read the input file
            string eachWordsPerLine;

            while (getline(in, eachWordsPerLine)) {
                // store the text of each line into our vector
                wordsPerLine.push_back(eachWordsPerLine);

                // inspect each word and its line numbers
                istringstream inputStr(eachWordsPerLine);
                // each word
                string word;

                while (inputStr >> word)
                    // store word into map, and give it a set of line numbers
                    wordMapLineNumber[word].insert(wordsPerLine.size());
            }
            
        }

        QueryResult query(const string &);

        // QueryResult could point to these function to access the value
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

QueryResult TextQuery::query(const string &q) {
    // store the new query into our data member
    queryStr = q;
    // reset the counter of words
    nWordOnFile = 0;

    for (const string &lineStr: wordsPerLine) {
        // how many s in each line
        size_t pos = 0;
        while ((pos = lineStr.find(q,pos)) != string::npos) {
            pos++;          // advance to serach the next query on the current line
            nWordOnFile++;  // counter
        }
    }

    // if the word is found, then make the QueryResult to point to dynanmically allocated of this class
    if (nWordOnFile)
        return QueryResult(new TextQuery(*this));

    // otherwise, just we give it a empty class
    return QueryResult(nullptr);
}

ostream& print(ostream &os, const QueryResult &dq) {

    if (dq.result) {    
        // show how many times the words is occurs
        cout << dq.result->getTheQueryStr() << " occur " << dq.result->howManyWordInFile()
            << (dq.result->howManyWordInFile() > 1 ? " times" : " time") << endl;

        // now show the line and the corresponding word
        // get the set first
        set<size_t> lineNumbers = dq.result->getWordMapLineNumber()[dq.result->getTheQueryStr()];
        for (const size_t number: lineNumbers)
            cout << "\t(line " << number << ") " <<  dq.result->getWordsPerLine()[number-1] << endl;

    }

    return os;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    // input the file into TextQuery
    ifstream in(argv[1]);

    if (in.fail()) {
        cerr << argv[1] << "is an invalid file" << endl;
        return -1;
    }

    TextQuery tq(in);

    while (true) {
        cout << "Enter word to look for, or q to quit: " ;
        string s;

        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    }

    in.close();

    return 0;
}