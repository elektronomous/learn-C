#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int (*pF)(void) = [] { return 42; };
    bool (*isShorter)(const string &s1, const string &s2) = [] (const string &s1, const string &s2) {
                                                                    return s1.size() < s2.size();
                                                            };
    /* 
        The empty capture list indicates that this lambda will not use any local variables
        from the surrounding function 
    */

    cout << pF() << endl;
    if (isShorter(string("hey"), string("hello")))
        cout << "True" << endl;
    

    return 0;
}