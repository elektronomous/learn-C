#include <iostream>
#include <memory>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "StrBlob.hpp"

class QueryResult;
using line_no = std::vector<std::string>::size_type;

class TextQuery {
    public:
            TextQuery(std::ifstream &in): file() {
            std::string text;
            while (getline(in, text)) {     // for each line in the file
                file.push_back(text);      // remember this line of text
                int n = file.size() - 1;   // the current line number

                std::istringstream ln(text);   // seperate the line into words
                std::string word;

                while (ln >> word) {
                    // if words isn't already in wm, subscripting adds new entry
                    std::shared_ptr<std::set<line_no>> &lines = wm[word];            // lines is shared_ptr
                    if (!lines)         // every time we see a new word, this pointer will nullptr
                        lines.reset(new std::set<line_no>);        // we use reset so the new word that appear will have allocate its own new memory address (its new line) 
                    lines->insert(n);   // insert this line number     
                        }
                    }
                }
       
        QueryResult query(const std::string &) const;
    
    private:
        StrBlob file;
        // map each of word to the set of the lines in which that word appears
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};



class QueryResult { 
    friend std::ostream &print(std::ostream&, QueryResult &);
    public:
        QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                                   StrBlob f):
                                   sought(s), lines(p), file(f) { }
    private:
        std::string sought;                             // word this query represents
        std::shared_ptr<std::set<line_no>> lines;       // line it's on
        StrBlob file;
};

QueryResult TextQuery::query(const std::string &sought) const {
    // we'll return a pointer to this set if we don't find sought
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    // use find and not a subscript operator to avoid adding words to wm!!!
    std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator soughtFind = wm.find(sought);

    if (soughtFind == wm.cend())        // if the word not found
        return QueryResult(sought, nodata, file);
    
    return QueryResult(sought, soughtFind->second, file);
}

std::ostream &print(std::ostream &os, QueryResult &q) {
    std::cout << q.sought << " occurs " << q.lines->size()
         << (q.lines->size() > 1 ? " times" : " time") << std::endl;
    
    // create the StrBlobPtr here for point to QueryResult
    for (const line_no &no: *q.lines) {
        StrBlobPtr toStrBlob(q.file, no);
        std::cout << "\t(line " << no << ") " << toStrBlob.deref() << std::endl; 
    }

    return os;
}

int main(int argc, char *argv[]) {
    if (argc != 2 ) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    ifstream in(argv[1]);

    if (in.fail()) {
        cerr << argv[1] << " is an invalid file." << endl;
        return -1;
    }

    TextQuery tq(in);
    while (true) {
        cout << "Enter text you wanna search: ";
        string inputStr;

        if (!(cin >> inputStr) || inputStr == "q") break;
        // store the result
        QueryResult qr(tq.query(inputStr));
        print(cout, qr);
    }


    in.close();
    return 0;
}