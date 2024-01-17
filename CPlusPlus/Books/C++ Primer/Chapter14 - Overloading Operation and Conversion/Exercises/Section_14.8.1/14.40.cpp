#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IsShorter {
    public:
        IsShorter(size_t thesize):
            sz(thesize) { }

        bool operator()(const string &s1, const string &s2) {
            return s1.size() < s2.size();
        }
    private:
        vector<string>::size_type sz;
};

void elimDups(vector<string> &words) {
    // sort words alphabetically
    sort(words.begin(), words.end());

    // unique reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    vector<string>::iterator endOfUnique = unique(words.begin(), words.end());

    // erase uses a vector operation to remove the nonunique elements
    words.erase(endOfUnique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    // put words in alphabetical order and remove duplicates
    elimDups(words);

    // resort by length, maintaining alphabetical order among words of the same 
    // length
    stable_sort(words.begin(), words.end(), IsShorter(sz));
}