#include <iostream>

using namespace std;

int main(void) { 
    int number;
    cout << "Enter number: ";

    while (! (cin >> number)) {
        /* when you input EOF, this loop will forever */
        if (cin.eof())
            // to handl the EOF
            clearerr(stdin);
        // turns off all the failure bits
        cin.clear();
        // clear the buffering that has invalid input
        cin.ignore(INT64_MAX, '\n');
        // ask the user again    
        cout << "Enter number: ";
    }

    cout << "You've enter number: " << number << endl;

    return 0;
}