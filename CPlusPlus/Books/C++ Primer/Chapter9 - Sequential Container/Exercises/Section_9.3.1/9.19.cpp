#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
    list<string> listStr;
    string str;

    while (cin >> str)
        listStr.push_back(str);
    
    for (list<string>::const_iterator it = listStr.cbegin(); it != listStr.cend(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}