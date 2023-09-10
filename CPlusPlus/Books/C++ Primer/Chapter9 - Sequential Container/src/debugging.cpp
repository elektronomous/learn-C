#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "Hello World";
    string::iterator itStr = str.begin() + 6;

    string result = str.replace(itStr, itStr + 5, "Hello");

    cout << "The string after replace: " << str << endl;
    cout << "The string result: " << result << endl; 
    return 0;
}