#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "HOW TO USE THIS PROGRAM:\n";
        cout << "IOFstreamState <inputFilename>\n";

        return 1;
    }

    ofstream out;

    out.open(argv[1]);

    if (out.fail()) {    
        // if a call to open fails, failbit is set
        cout << "You're opening invalid file. Please check your filename\n";
        return 1;
    }
    // otherwise, the good() will set to be true

    cout << "The file's successfully opened\n";

    out.close();
    return 0;
}