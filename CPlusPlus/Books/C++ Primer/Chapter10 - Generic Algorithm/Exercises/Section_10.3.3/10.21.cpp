#include <iostream>

using namespace std;

int main(void) {
    int i = 10;
    auto f = [&i] () -> bool { if (--i) return 0; else return 1;};

    while (i) {
        cout << i << " ";
        f();
    }
    cout << endl;

    return 0;
}