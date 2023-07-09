#include <iostream>

using std::cout,
      std::cin,
      std::endl;

void reset(int &val) {  // val is just another name for the object passed to reset
    val = 0;       // changes the value of the object to which i refers
}

int main(void) {
    int i = 42;
    // reset i to zero
    reset(i);      // the val is reference, so you need to pass an object
                   // that's reference to int

    cout << "i after reset: " << i << endl;

    return 0;
}