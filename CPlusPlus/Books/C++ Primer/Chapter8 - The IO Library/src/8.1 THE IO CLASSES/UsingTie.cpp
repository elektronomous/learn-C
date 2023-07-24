#include <iostream>

using namespace std;

int main(void) {
    int number;     // we use this variable as test

    // by default, library tied the cin to cout

    // old_tie points to the stream (if any) currently tied to cin;
    ostream *old_tie = cin.tie(nullptr);    // cin is no longer tied to cout
    

    cin.tie(&cerr);     // cin tied to the cerr

    cout << "Enter number: ";
    cin >> number;


    // if the prompt doesn't show first when reading an input
    // then we success to tied the cin to the cerr
    cin.tie(old_tie);
     

    return 0;
}