#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "HOW TO USE PROGRAM:\n"
             << "8.7 <inputFile> <outputFile>\n";
        return 1;
    }

    // open the first file
    ifstream in(argv[1]);       // implicit in

    if (in.fail()) {
        cerr << "The input file is invalid.\n";
        return 1;
    }

    ofstream out(argv[2]);      // implicit out and trunc
                                // REMEMBER: this will truncated your file's content

    if (out.fail()) {
        cerr << "The output file is invalid.\n";
        return 1;
    }

    while ()
    return 0;
}