#include <iostream>

using namespace std;

int main(void) {
    int val;
    cin >> val;

    // the state of the cin after doing >>
    auto streamState{cin.rdstate()};
    cout << streamState << "\n";

    // turn off the 

    if (cin.eof())
        cout << "eof() is called\n";
    else if (cin.fail())
        cout << "fail() is called\n";
    else if (cin.good())
        cout << "good() is called\n";

    return 0;
}