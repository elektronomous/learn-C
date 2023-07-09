#include <iostream>
#include <string>

using namespace std;

inline const string &shorterString(const string &s1, const string &s2) {
    return s1.size() < s2.size() ? s1 : s2;
}

/* 

cout << shorterString(s1, s2) << endl;

= will be inline by the compiler to:

cout << (s1.size() < s2.size() ? s1 : s2) << endl;

*/