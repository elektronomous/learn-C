#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string name = "Muhammad Faza Ak";

    // you can only insert a character
    // insert at the end of the name a character
    name.push_back('b');

    // display after inserted
    cout << name << endl;
    /*
        Muhammad Faza Akb
    */

    return 0;

}