#include <iostream>

using namespace std;

int main(void) {

    while (true) {
        int x;
        if (!(cin >> x) || !x ) break;
        cout << "The x: " << x << endl;
    }

    return 0;
}