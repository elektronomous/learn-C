#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
    // insert a half of list of name to another list
    list<string> listName {"muhammad", "faza","akbar"};
    list<string> anotherList {"anggun","lestari"};
    list<string>::iterator lastElement = listName.end();

    // before insert
    cout << "list of name: ";
    for (const string &str: listName)
        cout << str << " ";
    cout << endl;

    // insert
    listName.insert(lastElement, anotherList.begin(), anotherList.end());

    // after insert
    cout << "list of name: ";
    for (const string &str: listName)
        cout << str << " ";
    cout << endl;

    return 0;
}