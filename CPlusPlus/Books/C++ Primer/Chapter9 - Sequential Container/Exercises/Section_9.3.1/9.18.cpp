#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) { 
    deque<string> deqStr;
    string str;

    while (cin >> str) 
        deqStr.push_back(str);
    
    cout << "Inside deque of string: ";
    for (deque<string>::iterator it = deqStr.begin(); it != deqStr.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}