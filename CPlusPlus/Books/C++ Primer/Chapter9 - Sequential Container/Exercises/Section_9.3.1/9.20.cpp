#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    deque<int> deqint1,
               deqint2;

    for (const int &val: lint) {
        if (val % 2 == 0)
            deqint1.push_back(val);
        else
            deqint2.push_back(val);
    }

    cout << "Deqint1 is has even values: ";
    for (const int &val: deqint1)
        cout << val << " ";
    cout << endl;

    cout << "Deqint2 is has odd values: ";
    for (const int &val: deqint2)
        cout << val << " ";
    cout << endl;

    return 0;
}