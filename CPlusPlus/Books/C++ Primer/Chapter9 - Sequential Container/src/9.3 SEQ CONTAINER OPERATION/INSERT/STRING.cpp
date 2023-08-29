#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // your job is insert "faza" in front of "akbar"
    string name = "akbar";
    string insertName = "faza ";

    // before insert, dipslay the name
    cout << "Name: " << name << endl;
    /*
        akbar
    */

    // insert
    name.insert(name.begin(), insertName.begin(), insertName.end());
    // return iterator that point to 'f'

    // after insert, display the name
    cout << "Name: " << name << endl;
    /*
        faza akbar
    */

    return 0;
}