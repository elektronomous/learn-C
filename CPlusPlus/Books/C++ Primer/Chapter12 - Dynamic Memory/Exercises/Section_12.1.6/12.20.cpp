#include <iostream>
#include <memory>
#include <fstream>
#include "12.19.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <inputFile>" << endl;
        return 1;
    }

    ifstream in(argv[1]);
    string line;
    StrBlob storeLine;      // first newly created object, its data member automatically allocated
    StrBlobPtr pointLine(storeLine);

    if (in.fail()) {
        cerr << argv[1] << " is an invalid file." << endl;
        return -1;
    }

    while (getline(in, line)) 
        // store the line of words into StrBlob first
        storeLine.push_back(line);
    
    // now you print line by line by point to the StrBlob using StrBlobPtr
    for (size_t n = 0; n < storeLine.size(); n++) {
        // deref the line inside the StrBlob by using deref StrBlobPtr
        cout << pointLine.deref() << endl;
        // then increase the pointer so it advance to the next line
        pointLine.incr();
    }

    in.close();
    return 0;
}