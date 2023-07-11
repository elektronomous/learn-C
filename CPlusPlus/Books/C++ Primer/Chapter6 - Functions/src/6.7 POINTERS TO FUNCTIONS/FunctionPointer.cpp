#include <iostream>
#include <string>

using namespace std;

inline bool lengthCompare(const string &s1, const string &s2) {
    return  s1.size() < s2.size();
}

int main(void) {
    // the function pointer to point the function we declared above.
    bool (*pf)(const string &, const string &);

    // assign function pointer to the length compare
    pf = &lengthCompare;
    // or
    //      pf = lengthCompare;

    bool b1 = pf("Hello", "goodbye");               // calls the lengthCompare
    bool b2 = (*pf)("hello", "goodbye");            // equivalent calls
    bool b3 = lengthCompare("hello", "goodbye");    // equivalent calls

    cout << b1 << b2 << b3 << endl;

    return 0;
}