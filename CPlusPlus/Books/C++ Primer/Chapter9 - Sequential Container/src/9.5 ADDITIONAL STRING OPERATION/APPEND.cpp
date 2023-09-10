#include <iostream>
#include <string>

using namespace std;

int main(void) { 
    string s("C++ Primer"), s2 = s;
    s2.insert(s2.size(), " 4th edition.");      // s2 = "C++ Primer 4th edition."
    s.append(" 4th edition.");                  // equivalent to s2

    return 0;

}