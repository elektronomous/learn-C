#include <iostream>

int main(void) {
    int (*pF)(const int &n, const int &p) = [] (const int &n1, const int &n2) { return n1 + n2; };

    return 0;
}