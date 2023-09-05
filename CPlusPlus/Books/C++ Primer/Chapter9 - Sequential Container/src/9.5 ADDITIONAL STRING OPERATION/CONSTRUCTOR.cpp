#include <iostream>
#include <string>

using namespace std;

int main(void) {
    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i'};

    string s1(cp);          // copy up to the null; s1 = "Hello World!!!"
    string s2(noNull, 2);   // copy 2 characters from noNull; s2 == "Hi"
    string s3(noNull);      // undefined; noNull not null terminated
    string s4(cp + 6, 5);   // copy 5 characters starting from cp[6]; s4 = "World"
    string s5(s1, 6, 5);    // copy 5 characters starting from s1[6]; s5 = "World"
    string s6(s1, 6);       // copy from s1[6] to end of s1; s6 = "World!!!"
    string s7(s1, 6, 17);   // copy from s1[6] to end of s1; s7 = "World!!!"
    string s8(s1, 16);      // throws an out_of_range exception

    return 0; 
}