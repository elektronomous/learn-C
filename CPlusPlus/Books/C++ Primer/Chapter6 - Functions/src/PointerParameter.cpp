#include <iostream>

using std::cout,
      std::cin,
      std::endl;

void reset(int *val) {
    // the address of &i is passed to the val
    *val = 0;       // changes the value of the object to which ip points
    val = nullptr;  // changes only the local copy of ip; the argument is unchanged
}

int main(void) {
    int i = 42;
    // reset i to zero
    reset(&i);      // the val is pointer, so you need to pass an address

    cout << "i after reset: " << i << endl;

    return 0;
}