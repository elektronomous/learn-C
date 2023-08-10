#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream out("INPUT_TEXT.txt", ofstream::app);
    
    if (out.fail()) {
        cerr << "the input file is invalid.\n";
        return 1;
    }

    cout << out.tellp() << endl;

    return 0;
}