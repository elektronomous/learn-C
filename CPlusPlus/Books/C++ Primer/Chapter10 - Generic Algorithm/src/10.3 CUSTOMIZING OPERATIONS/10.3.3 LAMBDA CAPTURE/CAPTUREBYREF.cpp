#include <iostream>

using namespace std;

int main(void) {
    size_t val = 42;    // local variables

    // the object f2 contains reference to val
    auto f2 = [&val] { return val + 2; };
    val = 0;

    int j = f2();       // j is 2; f2 refers to val; it doesn't store it

}