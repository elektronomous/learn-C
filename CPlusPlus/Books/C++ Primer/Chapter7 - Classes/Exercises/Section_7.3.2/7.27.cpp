#include <iostream>
#include "Screen.hpp"

using namespace std;

int main(void) {
    Screen myScreen(5,5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}