#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "Hello World";

    string s2 = str.substr(0, 5);       // s2 = "Hello"
    string s3 = str.substr(6);          // s3 = "World"
    string s4 = str.substr(6, 11);      // s4 = "World"
    string s5 = str.substr(12);         // throws an out_of_range exception
}