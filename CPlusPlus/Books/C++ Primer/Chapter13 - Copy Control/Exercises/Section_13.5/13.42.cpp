#include <iostream>
#include <fstream>
#include "TextQuery.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    ifstream in(argv[1]);

    if (in.fail()) {
        cerr << argv[1] << " is an invalid file." << endl;
        return 1;
    }

    TextQuery tq(in);
    while(true) {
        string findWord;

        cout << "Input the word you want to find: ";
        cin >> findWord;

        if (findWord == "q") break;
        QueryResult qr(tq.query(findWord));
        print(cout, qr);
    }

    in.close();

    return 0;
}