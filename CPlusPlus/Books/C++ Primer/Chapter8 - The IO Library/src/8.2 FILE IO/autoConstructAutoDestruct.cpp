#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 1) {
        cerr << "HOW TO USE PROGRAM:\n";
        cerr << "eachIOFstreamState <filename_1> <filename_2> <filename_n> ...\n";
        return 1;
    }

    for (char **pArgv = argv; pArgv != argv + argc; ++pArgv) {
        /* 
         * = Because in is local to the while, it is created and destroyed
         *   on each iteration
         * = When an fstream object goes out of scope, the file it is bound to
         *   is automatically closed.
         */
        ifstream in(*pArgv);

        if (in) 
            cout << "Succes to open filename: " << *pArgv << endl;
        else
            cerr << "Couldn't open: " << string(*pArgv) << endl;
    }
    // when an fstream object is destroyed, close is called automatically

    return 0;
}