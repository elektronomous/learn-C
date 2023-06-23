#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int start = 0, end = 0;

    cout << "Enter start and end number: " << endl;
    cin >> start >> end;

    while (end >= start) {
        cout << start << endl;
        ++start;
    }

    return 0;

}