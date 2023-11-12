#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    ifstream in(argv[1]);

    if (in.fail()) {
        cerr << argv[1] << " is invalid file." << endl;
        return 1;
    }
    map<string, int> word_counts;
    string word;

    while (in >> word) {
        pair<map<string, int>::iterator, bool> retFromInsert = word_counts.insert({word, 0});

        // if the word is already there, the iterator part of the pair would point to the 
        // existing key.
        if (!retFromInsert.second)
            // so that's why we increment it by using -> operator.
            ++retFromInsert.first->second;
    }
}

/*
    The easier is using the subscript operator, because we dont need to examine the 
    value that's already inserted. On each iterator you just need to initiailze the
    value of the key with 0, then you can count the word like this:

        word_counts[word]++;

*/