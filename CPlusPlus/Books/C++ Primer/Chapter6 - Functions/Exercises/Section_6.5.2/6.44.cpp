#include <iostream>

using namespace std;

inline bool isShorter(const string &str1, const string &str2) {
    return (str1.size() < str2.size());
}