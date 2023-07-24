#include <iostream>

using namespace std;

int main(void) {
    cout << "Hi!" << endl;      // writes HI! and a null and newline, then flushes the buffer
    cout << "Hi!" << flush;     // writes hi, then flushes the buffer; adds no data

    cout << unitbuf;            // all writes will be flushed immediately
    /* any output is flushed immediately, no buffering */
    cout << nounitbuf;          // returns to normal buffering

    return 0;
}