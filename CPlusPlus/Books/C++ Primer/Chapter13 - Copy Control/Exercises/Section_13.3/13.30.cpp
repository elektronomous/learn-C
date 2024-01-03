#include <iostream>
#include "HasPtr_value.hpp"

using namespace std;

int main(void) {
    HasPtr p("Faza");
    HasPtr q("Anggun");

    cout << "P's value: " << p.getString() << endl;
    cout << "Q's value: " << q.getString() << endl;

    swap(p,q);

    cout << "P's value: " << p.getString() << endl;
    cout << "Q's value: " << q.getString() << endl;


    return 0;
}