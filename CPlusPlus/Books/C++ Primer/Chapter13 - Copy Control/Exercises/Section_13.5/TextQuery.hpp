#include <iostream>
#include <memory>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include "13.40.hpp"

class QueryResult;
using line_no = std::vector<std::string>::size_type;

class TextQuery {
    public:
            // 13.42.txt
            TextQuery(std::ifstream &in): file(new StrVec) {
            std::string text;
            while (getline(in, text)) {     // for each line in the file
                file->push_back(text);      // remember this line of text
                int n = file->size() - 1;   // the current line number

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
        // 13.42.txt
        std::shared_ptr<StrVec> file;     // input file
        // map each of word to the set of the lines in which that word appears
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};



class QueryResult { 
    friend std::ostream &print(std::ostream&, const QueryResult &);
    public:
        QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                                   std::shared_ptr<StrVec> f):              // 13.42.txt

                                   sought(s), lines(p), file(f) { }
    private:
        std::string sought;                             // word this query represents
        std::shared_ptr<std::set<line_no>> lines;       // line it's on
        std::shared_ptr<StrVec> file; // input file
};

QueryResult TextQuery::query(const std::string &sought) const {
    // we'll return a pointer to this set if we don't find sought
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    // use find and not a subscript operator to avoid adding words to wm!!!
    std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator soughtFind = wm.find(sought);

    if (soughtFind == wm.end())        // if the word not found
        return QueryResult(sought, nodata, file);
    
    return QueryResult(sought, soughtFind->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &q) {
    std::cout << q.sought << " occurs " << q.lines->size()
         << (q.lines->size() > 1 ? " times" : " time") << std::endl;
    
    for (const line_no &no: *q.lines) {
        std::cout << "\t(line " << no << ") " << *(q.file->begin() + no) << std::endl;
                                                 // 13.42.txt
    }

    return os;
}