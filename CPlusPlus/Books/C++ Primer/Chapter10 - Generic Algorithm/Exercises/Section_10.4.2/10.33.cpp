#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // tell user how to use the program
    if (argc != 4) {
        cerr << argv[0] << " <inputFile> <outputFile1> <outputFile2>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outFile1(argv[2], ofstream::out), 
             outFile2(argv[3], ofstream::out);      // explicit trunc the content of the file

    // look error for the input file
    if (inputFile.fail()) {
        cerr << argv[1] << " invalid name file." << endl;
        return 1;
    }

    // look error for the output file
    if (outFile1.fail()) {
        cerr << argv[2] << " invalid named file." << endl;
        return 1;
    }

    if (outFile2.fail()) {
        cerr << argv[3] << " invalid named file." << endl;
        return 1;
    }

    // read the input file using iterator
    istream_iterator<int> intFromFile(inputFile), eof_intFromFile;
    // write to the file via iterator
    ostream_iterator<int> writeFile1(outFile1, " "), writeFile2(outFile2, " ");

    // seperate the even numbers and odd numbers
    for_each(intFromFile, eof_intFromFile, [&](const int &i) { if (i % 2 == 0) writeFile1 = i; else writeFile2 = i; });

    return 0;
}