#include <iostream>
#include <string>

using namespace std;


inline bool lengthCompare(const string &s1, const string &s2) {
    return  s1.size() < s2.size();
}

// third parameter is a function type and is automatically treated as apointer to function
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
// or
//      void isBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

void useBigger(const string &s1, const string &s2, bool pf(const string &, const string&)) {
    if (pf(s1, s2))
        cout << "The first string is bigger than the second one\n";
    else
        cout << "The second string is bigger than the first one\n";
}

// using typedef
typedef bool Func1(const string &, const string&);
typedef decltype(lengthCompare) Func2;              // equivalent type

typedef bool (*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2;            // equivalent type

void useLower(const string &s1, const string &s2, Func1 f) {
    if (f(s1, s2))
        cout << "The first string is lower than the second one\n";
    else
        cout << "The second string is lower than the first one\n";
}

void pointerBigger(const string &s1, const string &s2, FuncP f) {
    cout << "The use bigger using function pointer\n";
    if (f(s1, s2))
        cout << "The first string is bigger than the second one\n";
    else
        cout << "The second string is bigger than the first one\n";
}

// use the typedef version

int main(void) {
    useBigger("Hello", "There", lengthCompare);

    return 0;
}