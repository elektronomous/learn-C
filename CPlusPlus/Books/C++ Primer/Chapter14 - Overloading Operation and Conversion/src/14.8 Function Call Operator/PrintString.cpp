#include <iostream>
#include <string>

using namespace std;

class PrintString {
    public:
        PrintString(ostream &o = cout, char c = ' '):
            os(cout), sep(c) { }
        
        void operator()(const string &s) const { os << s << sep; }
    
    private:
        ostream &os;        // stream on which to write
        char sep;           // character to print after each output
};

int main(void) {
    PrintString printer;                // uses the defaults; prints to cout
    string s = "muhammad faza akbar";
    printer(s);                         // print your name followed by a space on cout

    PrintString errors(cerr, '\n');
    errors("throw handle");             // prints s followed by new-line on cerr

    return 0;
}