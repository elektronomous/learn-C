#include <iostream>

using namespace std;

int main(void) {
    // local variables
    size_t val = 42;

    auto f = [val] { return val + 2; }; // copy val into callable object named f
    val = 0;
    int j  = f();       // return 44;

    return 0;
}

/* 
Because the value is copied when the lambda is created, subsequent changes to a
captured variable have no effect on the corresponding value inside the lambda.
*/